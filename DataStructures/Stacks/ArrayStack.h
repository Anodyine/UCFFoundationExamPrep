#ifndef STACKS_H
#define STACKS_H
#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the structure for the stack
struct stack {
    int data[MAX_SIZE]; // Array to store stack elements
    int top;            // Index of the top element
};

// Function to initialize the stack
void InitStack(struct stack* s);

// Function to check if the stack is empty
int isEmpty(struct stack* s);

// Function to check if the stack is full
int isFull(struct stack* s);

// Function to push an element onto the stack
void push(struct stack* s, int val);

// Function to pop an element from the stack
int pop(struct stack* s);

// Function to peek at the top element of the stack without removing it
int peek(struct stack* s);

#endif