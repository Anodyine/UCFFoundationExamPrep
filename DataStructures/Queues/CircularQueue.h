#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the circular queue
#define CIRCULAR_QUEUE_MAX_SIZE 5

// Define the structure for the circular queue
struct CircularQueue {
    int data[CIRCULAR_QUEUE_MAX_SIZE]; // Array to store queue elements
    int front;          // Index of the front element
    int rear;           // Index of the rear element
    int size;           // Number of elements in the queue
};

// Function to initialize the queue
void init(struct CircularQueue* q);

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q);

// Function to check if the queue is full
int isFull(struct CircularQueue* q);

// Function to add an element to the queue
void enqueue(struct CircularQueue* q, int val);

// Function to remove an element from the queue
int dequeue(struct CircularQueue* q);

// Function to get the front element of the queue without removing it
int front(struct CircularQueue* q);

#endif