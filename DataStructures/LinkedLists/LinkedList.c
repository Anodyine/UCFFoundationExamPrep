#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
    void *data;
    struct _Node *next;
} Node;

typedef struct {
    int length;
    char typeName[32];
    int typeSize;
    Node *head;
} LinkedList;

LinkedList* new_LinkedList (char *typeName, int typeSize) {
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

    return newList;
}

int LinkedList_Add (LinkedList *list, void *data) {
    /* Create Node */
    Node *newNode = malloc(sizeof(Node));
    newNode->data = malloc(list->typeSize);
    memcpy(newNode->data, data, list->typeSize);

    /* Adjust Pointers */
    newNode->next = list->head;
    list->head = newNode;

    /* Increase Length */
    list->length += 1;

    return 0;
}

int main (int) {
    char *currentFunctionName = malloc(80);    
    char *currentAction = malloc(200);    
    char *errorDescription = malloc(400);

    /* Testing new_LinkedList */
    currentFunctionName = "new_LinkedList";
    printf("Testing %s\n", currentFunctionName);

    currentAction = "creating a list";
    LinkedList* myList = new_LinkedList("int", sizeof(int));
    if (myList->head != NULL) {
        errorDescription = "myList->head did not point to NULL";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return 1;
    }
    if (myList->length != 0) {
        errorDescription = "myList->length was not 0";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return 1;
    }
    if (strcmp(myList->typeName, "int") != 0) {
        errorDescription = "myList->typeName was not saved";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return 1;
    }
    if (myList->typeSize != sizeof(int)) {
        errorDescription = "myList->typeSize was not saved";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return 1;
    }

    /* Testing LinkedList_Add */
    currentFunctionName = "LinkedList_Add";
    printf("Testing %s\n", currentFunctionName);

    currentAction = "adding a single int item";
    int *data = malloc(sizeof(int));
    *data = 9;
    LinkedList_Add(myList, data);
    if (myList->head == NULL) {
        errorDescription = "myList->head points to NULL";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return 1;
    }
    if (*(int *)myList->head->data != 9) {
        errorDescription = "the value of passed into add was not saved to the head element.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return 1;
    }
    free(data);


    printf("LinkedList Tests Passed.\n");
    return 0;
}