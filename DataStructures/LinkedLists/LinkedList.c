#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
    void* data;
    struct _Node* next;
} Node;

typedef struct {
    int length;
    char typeName[32];
    int typeSize;
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* new_LinkedList (char* typeName, int typeSize) {
    /* Validation */ 
    if (strlen(typeName) > 16) {
        printf("Your type name is greater than 16 bytes. This list does not handle that. Please make your name shorter or request a modification of this structure.\n");
        return NULL;
    }

    LinkedList *newList = malloc(sizeof(LinkedList));
    strcpy(newList->typeName, typeName);
    newList->typeSize = typeSize;
    newList->length = 0;
    newList->head = NULL;
    newList->tail = NULL;

    return newList;
}

int LinkedList_Add (LinkedList* list, void* data) {
    /* Create Node */
    Node* newNode = malloc(sizeof(Node));
    newNode->data = malloc(list->typeSize);
    memcpy(newNode->data, data, list->typeSize);

    /* Adjust Pointers */
    newNode->next = list->head;
    list->head = newNode;
    if (list->tail == NULL) {
        list->tail = newNode;
    }

    /* Increase Length */
    list->length += 1;

    return 0;
}

void* LinkedList_GetFirst (LinkedList* list) {
    return list->tail->data;
}

void* LinkedList_GetLast (LinkedList* list) {
    return list->head->data;
}

void* LinkedList_GetByIndex (LinkedList* list, int index) {
    if (index > list->length - 1) {
        printf("You tried to access an index that is greater than the length of the List.\n");
        return NULL;
    }

    if (index < 0) {
        printf("You tried to access an index that is less than 0.\n");
        return NULL;
    }

    Node* cursor = list->head;
    for (int i = 0; i < list->length - 1 - index; i++) {
        cursor = cursor->next;
    }

    return cursor->data;
}

int LinkedList_Destroy (LinkedList* list) {
    Node* cursor = list->head;
    while (cursor != NULL) {
        free(cursor->data);
        Node* temp = cursor;
        cursor = cursor->next;
        free(temp);
    }

    free(list);
    return 0;
}



int main (int) {
    char* currentFunctionName = malloc(80);    
    char* currentAction = malloc(200);    
    char* errorDescription = malloc(400);

    /* Testing new_LinkedList */
    currentFunctionName = "new_LinkedList";
    printf("Testing %s\n", currentFunctionName);

    currentAction = "creating a list";
    LinkedList* myList = new_LinkedList("int", sizeof(int));
    if (myList->head != NULL) {
        errorDescription = "myList->head did not point to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myList->tail != NULL) {
        errorDescription = "myList->tail did not point to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myList->length != 0) {
        errorDescription = "myList->length was not 0.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (strcmp(myList->typeName, "int") != 0) {
        errorDescription = "myList->typeName was not saved.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myList->typeSize != sizeof(int)) {
        errorDescription = "myList->typeSize was not saved.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    /* Testing LinkedList_Add */
    currentFunctionName = "LinkedList_Add";
    printf("Testing %s\n", currentFunctionName);
    currentAction = "adding a the first int item";
    int* temp = malloc(sizeof(int));
    *temp = 9;
    LinkedList_Add(myList, temp);
    if (myList->head == NULL) {
        errorDescription = "myList->head points to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (myList->tail == NULL) {
        errorDescription = "myList->tail points to NULL.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (*(int*)myList->head->data != 9) {
        errorDescription = "the value passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    currentAction = "adding a second int item";
    Node* previousHead = myList->head;
    *temp = 14;
    LinkedList_Add(myList, temp);
    if (myList->head == previousHead) {
        errorDescription = "myList->head was not updated.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }
    if (*(int*)myList->head->data != 14) {
        errorDescription = "the value passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return -1;
    }

    free(temp);

    currentFunctionName = "LinkedList_GetByIndex";
    printf("Testing %s\n", currentFunctionName);
    int firstElement = *(int*)LinkedList_GetByIndex(myList, 0);
    if (firstElement != 9) {
        currentAction = "getting the item at index 0";
        errorDescription = "Expected: 9";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, firstElement);
        return -1;
    }
    int secondElement = *(int*)LinkedList_GetByIndex(myList, 1);
    if (secondElement != 14) {
        currentAction = "getting the item at index 1";
        errorDescription = "Expected: 14";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, secondElement);
        return -1;
    }

    currentFunctionName = "LinkedList_GetFirst";
    printf("Testing %s\n", currentFunctionName);
    int firstElement2 = *(int*)LinkedList_GetFirst(myList);
    if (firstElement2 != 9) {
        currentAction = "getting the first item";
        errorDescription = "Expected: 9";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, firstElement2);
        return -1;
    }

    currentFunctionName = "LinkedList_GetLast";
    printf("Testing %s\n", currentFunctionName);
    int lastElement = *(int*)LinkedList_GetLast(myList);
    if (lastElement != 14) {
        currentAction = "getting the last item";
        errorDescription = "Expected: 14";
        printf("%s test failed: After %s, %s, Actual: %d\n", currentFunctionName, currentAction, errorDescription, lastElement);
        return -1;
    }

    currentFunctionName = "LinkedList_Destroy";
    printf("Testing %s\n", currentFunctionName);
    LinkedList_Destroy(myList);

    printf("LinkedList Tests Passed.\n");
    return 0;
}