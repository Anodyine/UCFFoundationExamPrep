#include "ArrayStack.h"

// Function to initialize the stack
void ArrayStack_init(struct ArrayStack* s) {
    s->top = -1; // Initialize top to -1 indicating the stack is empty
}

// Function to check if the stack is empty
int ArrayStack_IsEmpty(struct ArrayStack* s) {
    return s->top == -1;
}

// Function to check if the stack is full
int ArrayStack_IsFull(struct ArrayStack* s) {
    return s->top == ARRAY_STACK_MAX_SIZE - 1;
}

// Function to push an element onto the stack
void ArrayStack_Push(struct ArrayStack* s, int val) {
    if (ArrayStack_IsFull(s)) {
        printf("Stack is full. Cannot push %d\n", val);
        return;
    }
    s->data[++(s->top)] = val; // Increment top and add the element to the stack
    printf("Pushed %d onto the stack\n", val);
}

// Function to pop an element from the stack
int ArrayStack_Pop(struct ArrayStack* s) {
    if (ArrayStack_IsEmpty(s)) {
        printf("Stack is empty. Cannot pop\n");
        return -1; // Return an error value
    }
    return s->data[(s->top)--]; // Return the top element and decrement top
}

// Function to peek at the top element of the stack without removing it
int ArrayStack_Peek(struct ArrayStack* s) {
    if (ArrayStack_IsEmpty(s)) {
        printf("Stack is empty. Cannot peek\n");
        return -1; // Return an error value
    }
    return s->data[s->top]; // Return the top element
}
