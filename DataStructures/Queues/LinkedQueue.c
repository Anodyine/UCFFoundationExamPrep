#include "LinkedQueue.h"

// Function to initialize the queue
void InitQueue(struct queue *q)
{
    q->front = NULL; // Initialize front to NULL
    q->back = NULL;  // Initialize back to NULL
}

// Function to check if the queue is empty
int empty(struct queue *q)
{
    return q->front == NULL;
}

// Function to add an element to the queue
void enqueue(struct queue *q, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // Allocate memory for a new node
    newNode->data = val;                                               // Set the data of the new node
    newNode->next = NULL;                                              // Set the next pointer of the new node to NULL
    if (q->back == NULL)
    {                       // If the queue is empty
        q->front = newNode; // Set front to the new node
        q->back = newNode;  // Set back to the new node
    }
    else
    {
        q->back->next = newNode; // Link the new node to the end of the queue
        q->back = newNode;       // Update the back pointer to the new node
    }
    printf("Enqueued %d\n", val);
}

// Function to remove an element from the queue
int dequeue(struct queue *q)
{
    if (empty(q))
    { // If the queue is empty
        printf("Queue is empty. Cannot dequeue\n");
        return -1; // Return an error value
    }
    struct node *temp = q->front; // Store a temporary pointer to the front node
    int val = temp->data;         // Get the data from the front node
    q->front = q->front->next;    // Move the front pointer to the next node
    if (q->front == NULL)
    {                   // If the queue is now empty
        q->back = NULL; // Set the back pointer to NULL
    }
    free(temp); // Free the memory of the old front node
    return val; // Return the data from the dequeued node
}

// Function to get the front element of the queue without removing it
int front(struct queue *q)
{
    if (empty(q))
    { // If the queue is empty
        printf("Queue is empty. Cannot peek\n");
        return -1; // Return an error value
    }
    return q->front->data; // Return the data at the front of the queue
}
