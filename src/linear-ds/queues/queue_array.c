#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct Queue {
    int* queue;
    int front, rear, max_size;
} * queue;

queue queue_constructor(int max_size) {
    queue q = (queue)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->max_size = max_size;
    q->queue = (int*)malloc(max_size * sizeof(int));
    return q;
}

bool is_empty(queue q) {
    return q->front == -1;
}

bool is_full(queue q) {
    return q->front == 0 && q->rear == q->max_size - 1;
}

int get_size(queue q) {
    if (is_empty(q))
        return 0;
    // Though both start at -1, front is also incremented on the 1st insertion
    return q->rear - q->front + 1;
}

bool enQueue(queue q, int elem) {
    if (is_full(q))
        return false;
    // Increment rear and assign new value
    q->queue[++q->rear] = elem;
    // For 1st insertion, front should be set to 0
    if (is_empty(q))
        q->front = 0;
    return true;
}

bool deQueue(queue q) {
    if (is_empty(q))
        return false;
    // Increment front
    ++q->front;
    // When queue property is being violated, we reset it
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return true;
}

int peek_front(queue q) {
    if (is_empty(q))
        return QUEUE_EMPTY;
    return q->queue[q->front];
}

int peek_rear(queue q) {
    if (is_empty(q))
        return QUEUE_EMPTY;
    return q->queue[q->rear];
}

int poll(queue q) {
    if (is_empty(q))
        return QUEUE_EMPTY;
    // Store before incrementing front
    int result = q->queue[q->front++];
    // When queue property is being violated, we reset it
    if (q->front >= q->rear)
        q->front = q->rear = -1;
    return result;
}

int contains(queue q, int key) {
    if (is_empty(q))
        return QUEUE_EMPTY;
    for (register short i = q->front; i <= q->rear; ++i)
        if (q->queue[i] == key)
            return i;
    return -1;
}

void print_queue(queue q) {
    if (is_empty(q))
        printf("\nThe Queue is Empty.\n");
    else {
        printf("\nThe Queue is :\n");
        for (register short i = q->front; i <= q->rear; ++i)
            printf("%d\t", q->queue[i]);
    }
}

int main(int argc, char const* argv[]) {
    queue q = queue_constructor(5);
    enQueue(q, 5);
    enQueue(q, 1);
    enQueue(q, 4);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 6);
    print_queue(q);
    return 0;
}
