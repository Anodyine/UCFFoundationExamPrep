#include "ArrayStack.h"

// Function to initialize the stack
void InitStack(struct stack* s) {
    s->top = -1; // Initialize top to -1 indicating the stack is empty
}

// Function to check if the stack is empty
int isEmpty(struct stack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(struct stack* s) {
    return s->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct stack* s, int val) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", val);
        return;
    }
    s->data[++(s->top)] = val; // Increment top and add the element to the stack
    printf("Pushed %d onto the stack\n", val);
}

// Function to pop an element from the stack
int pop(struct stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop\n");
        return -1; // Return an error value
    }
    return s->data[(s->top)--]; // Return the top element and decrement top
}

// Function to peek at the top element of the stack without removing it
int peek(struct stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek\n");
        return -1; // Return an error value
    }
    return s->data[s->top]; // Return the top element
}
