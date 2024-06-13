#include "../DataStructures/Queues/LinkedQueue.h"

// Main function to demonstrate queue operations
int main()
{
    struct LinkedQueue myQueue;
    LinkedQueue_Init(&myQueue);
    LinkedQueue_Enqueue(&myQueue, 10);
    LinkedQueue_Enqueue(&myQueue, 20);
    LinkedQueue_Enqueue(&myQueue, 30);
    printf("Front element is %d\n", LinkedQueue_Front(&myQueue));
    printf("Dequeued %d from the queue\n", LinkedQueue_Dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", LinkedQueue_Dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", LinkedQueue_Dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", LinkedQueue_Dequeue(&myQueue)); // Attempt to dequeue from an empty queue return 0;
}