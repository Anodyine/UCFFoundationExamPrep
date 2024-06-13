#include "../DataStructures/Queues/LinkedQueue.h"

// Main function to demonstrate queue operations
int main()
{
    struct queue myQueue;
    InitQueue(&myQueue);
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    printf("Front element is %d\n", front(&myQueue));
    printf("Dequeued %d from the queue\n", dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", dequeue(&myQueue)); // Attempt to dequeue from an empty queue return 0;
}