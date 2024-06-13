#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define ARRAY_STACK_MAX_SIZE 100

// Define the structure for the stack
struct ArrayStack {
    int data[ARRAY_STACK_MAX_SIZE]; // Array to store stack elements
    int top;            // Index of the top element
};

// Function to initialize the stack
void ArrayStack_init(struct ArrayStack* s);

// Function to check if the stack is empty
int ArrayStack_IsEmpty(struct ArrayStack* s);

// Function to check if the stack is full
int ArrayStack_IsFull(struct ArrayStack* s);

// Function to push an element onto the stack
void ArrayStack_Push(struct ArrayStack* s, int val);

// Function to pop an element from the stack
int ArrayStack_Pop(struct ArrayStack* s);

// Function to peek at the top element of the stack without removing it
int ArrayStack_Peek(struct ArrayStack* s);

#endif