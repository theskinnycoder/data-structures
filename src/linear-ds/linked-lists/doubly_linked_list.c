#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LIST_EMPTY INT_MIN

typedef struct List {
    struct Node {
        int data;
        struct Node *next, *prev;
    } * head, *tail;
    int size;
} * list;

typedef struct Node* node;

node node_constructor(int data) {
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

list list_constructor() {
    list l = (list)malloc(sizeof(struct List));
    l->head = l->tail = NULL;
    l->size = 0;
    return l;
}

bool is_empty(list l) {
    return l->size == 0;
}

int get_size(list l) {
    return l->size;
}

void prepend(list l, int elem) {
    node newNode = node_constructor(elem);
    if (is_empty(l))
        l->tail = newNode;
    else {
        newNode->next = l->head;
        l->head->prev = newNode;
    }
    l->head = newNode;
    ++l->size;
}

void append(list l, int elem) {
    node newNode = node_constructor(elem);
    if (is_empty(l))
        l->head = newNode;
    else {
        l->tail->next = newNode;
        newNode->prev = l->tail;
    }
    l->tail = newNode;
    ++l->size;
}

bool pop_front(list l) {
    if (is_empty(l))
        return false;
    node temp = l->head;
    l->head = l->head->next;
    l->head->prev = NULL;
    free(temp);
    --l->size;
    return true;
}

bool pop_rear(list l) {
    if (is_empty(l))
        return false;
    node temp = l->tail;
    l->tail = l->tail->prev;
    l->tail->next = NULL;
    free(temp);
    --l->size;
    return true;
}

int peek_front(list l) {
    if (is_empty(l))
        return LIST_EMPTY;
    return l->head->data;
}

int peek_rear(list l) {
    if (is_empty(l))
        return LIST_EMPTY;
    return l->tail->data;
}

int poll_front(list l) {
    if (is_empty(l))
        return LIST_EMPTY;
    node temp = l->head;
    int result = l->head->data;
    l->head = l->head->next;
    free(temp);
    --l->size;
    return result;
}

int poll_rear(list l) {
    if (is_empty(l))
        return LIST_EMPTY;
    node temp = l->tail;
    int result = l->tail->data;
    l->tail = l->tail->prev;
    l->tail->next = NULL;
    free(temp);
    --l->size;
    return result;
}

bool contains(list l, int key) {
    if (is_empty(l))
        return false;
    node current = l->head;
    while (current != NULL) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

void print_list(list l) {
    if (is_empty(l))
        printf("\nThe List is Empty.\n");
    else {
        printf("\nThe List is :\n");
        node current = l->head;
        while (current != NULL) {
            printf("%d-->", current->data);
            current = current->next;
        }
    }
}

int main(int argc, char const* argv[]) {
    list l = list_constructor();
    prepend(l, 5);
    append(l, 1);
    prepend(l, 4);
    append(l, 2);
    prepend(l, 3);
    print_list(l);
    return 0;
}
