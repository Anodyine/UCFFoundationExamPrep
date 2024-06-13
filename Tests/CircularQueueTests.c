#include "../DataStructures/Queues/CircularQueue.h"

// Main function to demonstrate queue operations
int main() {
    struct CircularQueue myQueue;
    init(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    enqueue(&myQueue, 60); // Attempt to enqueue into a full queue

    printf("Front element is %d\n", front(&myQueue));

    printf("Dequeued %d from the queue\n", dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", dequeue(&myQueue));
    printf("Dequeued %d from the queue\n", dequeue(&myQueue)); // Attempt to dequeue from an empty queue

    return 0;
}
