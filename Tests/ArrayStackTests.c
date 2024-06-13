#include "../DataStructures/Stacks/ArrayStack.h"

// Main function to demonstrate stack operations
int main() {
    struct ArrayStack myStack;
    ArrayStack_init(&myStack);

    ArrayStack_Push(&myStack, 10);
    ArrayStack_Push(&myStack, 20);
    ArrayStack_Push(&myStack, 30);

    printf("Top element is %d\n", ArrayStack_Peek(&myStack));

    printf("Popped %d from the stack\n", ArrayStack_Pop(&myStack));
    printf("Popped %d from the stack\n", ArrayStack_Pop(&myStack));
    printf("Popped %d from the stack\n", ArrayStack_Pop(&myStack));
    printf("Popped %d from the stack\n", ArrayStack_Pop(&myStack)); // Attempt to pop from an empty stack

    return 0;
}
