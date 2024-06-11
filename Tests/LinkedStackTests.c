#include "../DataStructures/Stacks/LinkedStack.h"
#include "../Shared/Point.h"

int testLinkedStackWithInts();

int main (int) {
    if (testLinkedStackWithInts() == -1) {
        return -1;
    }

    printf("All Tests Passed.");
}

int testLinkedStackWithInts() {
    char* currentFunctionName;    
    char* currentAction;    
    char* errorDescription;

    printf("Testing Linked Stack with ints\n");
    currentFunctionName = "new_LinkedStack";
    printf("Testing %s\n", currentFunctionName);

    currentAction = "creating a stack";
    LinkedStack* myStack = new_LinkedStack("int", sizeof(int));
    if (myStack->head != NULL) {
        errorDescription = "myStack->head did not point to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myStack->length != 0) {
        errorDescription = "myStack->length was not 0.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    
    currentFunctionName = "LinkedStack_Push";
    printf("Testing %s\n", currentFunctionName);
    currentAction = "pushing the first int item";
    int* temp = malloc(sizeof(int));
    *temp = 9;
    LinkedStack_Push(myStack, temp);
    if (myStack->head == NULL) {
        errorDescription = "myStack->head points to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (*(int*)myStack->head->data != 9) {
        errorDescription = "the value passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    currentAction = "adding a second int item";
    StackNode* previousHead = myStack->head;
    *temp = 14;
    LinkedStack_Push(myStack, temp);
    if (myStack->head == previousHead) {
        errorDescription = "myStack->head was not updated.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (*(int*)myStack->head->data != 14) {
        errorDescription = "the value passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    return 0;
}