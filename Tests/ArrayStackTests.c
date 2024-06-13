#include "../DataStructures/Stacks/ArrayStack.h"

// Main function to demonstrate stack operations
int main() {
    struct stack myStack;
    InitStack(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element is %d\n", peek(&myStack));

    printf("Popped %d from the stack\n", pop(&myStack));
    printf("Popped %d from the stack\n", pop(&myStack));
    printf("Popped %d from the stack\n", pop(&myStack));
    printf("Popped %d from the stack\n", pop(&myStack)); // Attempt to pop from an empty stack

    return 0;
}
