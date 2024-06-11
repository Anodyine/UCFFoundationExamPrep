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
   
    currentFunctionName = "LinkedStack_IsEmpty";
    printf("Testing %s\n", currentFunctionName);
    currentAction = "calling is empty";
    if (LinkedStack_IsEmpty(myStack) == false) {
        errorDescription = "IsEmpty returned true after creation";
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
  
    currentFunctionName = "LinkedStack_IsEmpty";
    printf("Testing %s\n", currentFunctionName);
    currentAction = "calling is empty";
    if (LinkedStack_IsEmpty(myStack) == true) {
        errorDescription = "IsEmpty returned false after creating an item";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    currentFunctionName = "LinkedStack_Peek";
    printf("Testing %s\n", currentFunctionName);
    int firstElement = *(int*)LinkedStack_Peek(myStack);
    if (firstElement != 14) {
        currentAction = "getting the item on the top";
        errorDescription = "Expected: 14";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, firstElement);
        return -1;
    }
    LinkedStack_RemoveTop(myStack);
    int secondElement = *(int*)LinkedStack_Peek(myStack);
    if (secondElement != 9) {
        currentAction = "getting the item on the top after removing one";
        errorDescription = "Expected: 9";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, secondElement);
        return -1;
    }

    LinkedStack_Destroy(myStack);

    return 0;
}