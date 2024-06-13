#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct QueueNode
{
    int data;          // Data stored in the node
    struct QueueNode *next; // Pointer to the next node
};

// Define the structure for the queue
struct LinkedQueue
{
    struct QueueNode *front; // Pointer to the front (head) of the queue
    struct QueueNode *back;  // Pointer to the back (tail) of the queue
};

// Function to initialize the queue
void LinkedQueue_Init(struct LinkedQueue *q);

// Function to check if the queue is empty
int LinkedQueue_IsEmpty(struct LinkedQueue *q);

// Function to add an element to the queue
void LinkedQueue_Enqueue(struct LinkedQueue *q, int val);

// Function to remove an element from the queue
int LinkedQueue_Dequeue(struct LinkedQueue *q);

// Function to get the front element of the queue without removing it
int LinkedQueue_Front(struct LinkedQueue *q);

#endif