#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct Queue {
    struct Node {
        int data;
        struct Node* next;
    } * front, *rear;
    int size;
} * queue;

typedef struct Node* node;

node node_constructor(int data) {
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

queue queue_constructor() {
    queue q = (queue)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

bool is_empty(queue q) {
    return q->size == 0;
}

int get_size(queue q) {
    return q->size;
}

void enQueue(queue q, int elem) {
    node newNode = node_constructor(elem);
    if (is_empty(q))
        q->front = newNode;
    else
        q->rear->next = newNode;
    q->rear = newNode;
    ++q->size;
}

bool deQueue(queue q) {
    if (is_empty(q))
        return false;
    node temp = q->front;
    q->front = q->front->next;
    free(temp);
    --q->size;
    return true;
}

int peek_front(queue q) {
    if (is_empty(q))
        return QUEUE_EMPTY;
    return q->front->data;
}

int peek_rear(queue q) {
    if (is_empty(q))
        return QUEUE_EMPTY;
    return q->rear->data;
}

int poll(queue q) {
    if (is_empty(q))
        return QUEUE_EMPTY;
    node temp = q->front;
    int result = q->front->data;
    q->front = q->front->next;
    free(temp);
    --q->size;
    return result;
}

bool contains(queue q, int key) {
    if (is_empty(q))
        return false;
    node current = q->front;
    while (current != NULL) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

void print_queue(queue q) {
    if (is_empty(q))
        printf("\nThe Queue is Empty.\n");
    else {
        printf("\nThe Queue is :\n");
        node current = q->front;
        while (current != NULL) {
            printf("%d\t", current->data);
            current = current->next;
        }
    }
}

int main(int argc, char const* argv[]) {
    queue q = queue_constructor();
    enQueue(q, 5);
    enQueue(q, 1);
    enQueue(q, 4);
    enQueue(q, 2);
    enQueue(q, 3);
    print_queue(q);
    return 0;
}
