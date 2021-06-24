#include <stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == MAX_SIZE - 1;
}

int push(int elem) {
    if (is_full())
        return 0;
    ++top;
    stack[top] = elem;
    return 1;
}

int pop() {
    if (is_empty())
        return 0;
    --top;
    return 1;
}

int peek() {
    if (is_empty())
        return -9999;
    return stack[top];
}

int poll() {
    if (is_empty())
        return -9999;
    return stack[top--];
}

int contains(int key) {
    if (is_empty())
        printf("The Stack is Empty");
    else {
        for (int i = 0; i <= top; ++i)
            if (stack[i] == key)
                return i;
        return -1;
    }
}

int print_stack() {
    if (is_empty())
        printf("The Stack is Empty");
    else {
        printf("The Stack is :\n");
        for (int i = top; i >= 0; --i)
            printf("%d\n", stack[i]);
    }
}

int main(int argc, char const* argv[]) {
    push(5);
    push(1);
    push(4);
    push(2);
    push(3);
    print_stack();
    return 0;
}

/*
 * No booleans
 * Global Variables!
 * No structs, & typedefs
 * No heap memory, not dynamic
 * No useful macros
 */
