#include "CircularQueue.h"

// Function to initialize the queue
void init(struct CircularQueue* q) {
    q->front = 0;  // Initialize front to 0
    q->rear = -1;  // Initialize rear to -1
    q->size = 0;   // Initialize size to 0
}

// Function to check if the queue is empty
int isEmpty(struct CircularQueue* q) {
    return q->size == 0;
}

// Function to check if the queue is full
int isFull(struct CircularQueue* q) {
    return q->size == CIRCULAR_QUEUE_MAX_SIZE;
}

// Function to add an element to the queue
void enqueue(struct CircularQueue* q, int val) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", val);
        return;
    }
    q->rear = (q->rear + 1) % CIRCULAR_QUEUE_MAX_SIZE; // Circular increment of rear
    q->data[q->rear] = val;             // Insert the element
    q->size++;                          // Increment the size
    printf("Enqueued %d\n", val);
}

// Function to remove an element from the queue
int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue\n");
        return -1; // Return an error value
    }
    int val = q->data[q->front];        // Get the front element
    q->front = (q->front + 1) % CIRCULAR_QUEUE_MAX_SIZE; // Circular increment of front
    q->size--;                          // Decrement the size
    return val;
}

// Function to get the front element of the queue without removing it
int front(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek\n");
        return -1; // Return an error value
    }
    return q->data[q->front]; // Return the front element
}