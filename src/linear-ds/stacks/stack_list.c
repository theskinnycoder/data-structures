#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_EMPTY INT_MIN

typedef struct Stack {
    struct Node {
        int data;
        struct Node* next;
    } * top;
    int size, max_size;
} * stack;

typedef struct Node* node;

node node_constructor(int data) {
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

stack stack_constructor(int max_size) {
    stack s = (stack)malloc(sizeof(struct Stack));
    s->max_size = max_size;
    s->top = NULL;
    s->size = 0;
    return s;
}

bool is_empty(stack s) {
    return s->size <= 0;
}

bool is_full(stack s) {
    return s->size >= s->max_size;
}

int get_size(stack s) {
    return s->size;
}

bool push(stack s, int elem) {
    if (is_full(s))
        return false;
    node newNode = node_constructor(elem);
    newNode->next = s->top;
    s->top = newNode;
    ++s->size;
    return true;
}

bool pop(stack s) {
    if (is_empty(s))
        return false;
    node temp = s->top;
    s->top = s->top->next;
    free(temp);
    --s->size;
    return true;
}

int peek(stack s) {
    if (is_empty(s))
        return STACK_EMPTY;
    return s->top->data;
}

int poll(stack s) {
    if (is_empty(s))
        return STACK_EMPTY;
    node temp = s->top;
    int result = s->top->data;
    s->top = s->top->next;
    free(temp);
    --s->size;
    return result;
}

bool contains(stack s, int key) {
    if (is_empty(s))
        return false;
    node current = s->top;
    while (current != NULL) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

void print_stack(stack s) {
    if (is_empty(s))
        printf("\nThe Stack is Empty.\n");
    else {
        printf("\nThe Stack is :\n");
        node current = s->top;
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}

int main(int argc, char const* argv[]) {
    stack s = stack_constructor(5);
    push(s, 5);
    push(s, 1);
    push(s, 4);
    push(s, 2);
    push(s, 3);
    print_stack(s);
    return 0;
}
