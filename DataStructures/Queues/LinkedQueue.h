#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node
{
    int data;          // Data stored in the node
    struct node *next; // Pointer to the next node
};

// Define the structure for the queue
struct queue
{
    struct node *front; // Pointer to the front (head) of the queue
    struct node *back;  // Pointer to the back (tail) of the queue
};

// Function to initialize the queue
void InitQueue(struct queue *q);

// Function to check if the queue is empty
int empty(struct queue *q);

// Function to add an element to the queue
void enqueue(struct queue *q, int val);

// Function to remove an element from the queue
int dequeue(struct queue *q);

// Function to get the front element of the queue without removing it
int front(struct queue *q);