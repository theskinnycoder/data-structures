#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_EMPTY INT_MIN

typedef struct Stack {
    int* stack;
    int top, max_size;
} * stack;

stack stack_constructor(int max_size) {
    stack s = (stack)malloc(sizeof(struct Stack));
    s->max_size = max_size;
    s->top = -1;
    s->stack = (int*)malloc(max_size * sizeof(int));
    return s;
}

bool is_empty(stack s) {
    return s->top == -1;
}

bool is_full(stack s) {
    return s->top == s->max_size - 1;
}

int get_size(stack s) {
    return s->top + 1;
}

bool push(stack s, int elem) {
    if (is_full(s))
        return false;
    s->stack[++s->top] = elem;
    return true;
}

bool pop(stack s) {
    if (is_empty(s))
        return false;
    --s->top;
    return true;
}

int peek(stack s) {
    if (is_empty(s))
        return STACK_EMPTY;
    return s->stack[s->top];
}

int poll(stack s) {
    if (is_empty(s))
        return STACK_EMPTY;
    return s->stack[s->top--];
}

int contains(stack s, int key) {
    if (is_empty(s))
        return STACK_EMPTY;
    for (register short i = 0; i <= s->top; ++i)
        if (s->stack[i] == key)
            return i;
    return -1;
}

void print_stack(stack s) {
    if (is_empty(s))
        printf("\nThe Stack is Empty.\n");
    else {
        printf("\nThe Stack is :\n");
        for (register short i = s->top; i >= 0; --i)
            printf("%d\n", s->stack[i]);
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
