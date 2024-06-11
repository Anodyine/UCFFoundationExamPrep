#include "LinkedStack.h"

/*
    This generic stack implemented with a linked list that stores a list of void pointers. To access the data, is required to type cast the 
    return value of LinkedStack_Peek. To help with that, a typeName property is provided in case you are working with 
    multiple types of lists and need to differentiate between them. The stack also has a typeSize property that tracks the size that each data item 
    will have in memory. The author recommeneds to only modify the stack through the given functions.

*/

LinkedStack* new_LinkedStack (char* typeName, int typeSize) {
    if (strlen(typeName) > 100) {
        printf("Your type name is greater than 100 bytes. This stack does not handle that. Please make your name shorter or request a modification of this structure.\n");
        return NULL;
    }

    LinkedStack *newStack = malloc(sizeof(LinkedStack));
    strcpy(newStack->typeName, typeName);
    newStack->typeSize = typeSize;
    newStack->length = 0;
    newStack->head = NULL;

    return newStack;
}

void LinkedStack_Push (LinkedStack* stack, void* data) {
    /* Create Node */
    StackNode* newNode = malloc(sizeof(StackNode));

    /* Update Pointers */
    newNode->next = stack->head;
    stack->head = newNode;

    /* Copy Data */
    newNode->data = malloc(stack->typeSize);
    memcpy(newNode->data, data, stack->typeSize);

    /* Increase Length */
    stack->length++;

    return;
}

void* LinkedStack_Peek (LinkedStack* stack) {
    return stack->head->data;
}

bool LinkedStack_IsEmpty (LinkedStack* stack) {
    return stack->length == 0;
}

void LinkedStack_RemoveTop (LinkedStack* stack) {
    if (LinkedStack_IsEmpty(stack)) {
        printf("Cannot remove an element from an empty stack");
        return;
    }

    StackNode* cursor = stack->head;

    free(cursor->data);

    if (stack->length == 1) {
        stack->head = NULL;
    } else {
        stack->head = cursor->next;
    }

    free(cursor);
    stack->length--;

    return;
}
