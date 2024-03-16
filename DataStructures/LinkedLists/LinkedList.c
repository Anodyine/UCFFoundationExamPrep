#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    With this generic linked list, the author intends that the user provide a string that represents 
    the data type of the node. The property "typeName", is provided for that purpose, but no validation is done 
    ensure the data type matches any particular known type.  To access the data, the user 
    of this structure may need to typecast the void pointer, called data, to a 
    particular pointer type based on the string stored in typeName.  (I. e, the user can use the "typeName" of the node to determine 
    which pointer type to typecast to.)
*/

typedef struct _Node {
    char typeName[16];
    void *data;
    struct _Node *next;
} Node;

typedef struct {
    int length;
    Node *head;
} LinkedList;

LinkedList* new_LinkedList () {
    LinkedList *newList = malloc(sizeof(LinkedList));
    newList->length = 0;
    newList->head = NULL;

    return newList;
}

int LinkedList_Add (LinkedList *list, char *typeName, void *data) {
    /* Validation */ 
    if (strlen(typeName) > 16) {
        printf("Your type name is greater than 16 bytes. This list does not handle that. Please make your name shorter or request a modification of this structure.\n");
        return 1;
    }

    /* Create Node */
    Node *newNode = malloc(sizeof(Node));
    strcpy(newNode->typeName, typeName);
    newNode->data = data;

    /* Adjust Pointers */
    newNode->next = list->head;
    list->head = newNode;
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
    LinkedList* myList = new_LinkedList();
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

    /* Testing LinkedList_Add */
    currentFunctionName = "LinkedList_Add";
    printf("Testing %s\n", currentFunctionName);

    currentAction = "adding a single int item";
    int *data = malloc(sizeof(int));
    *data = 9;
    LinkedList_Add(myList, "int", data);
    if (myList->head == NULL) {
        errorDescription = "myList->head points to NULL";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return 1;
    }

    if (myList->head->data != data) {
        errorDescription = "myList->head->data does not point to the pointer that was passed in.";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return 1;
    }

    if (*(int*)myList->head->data != 9) {
        errorDescription = "cannot access original value that was stored";
        printf("%s test failed: After %s, %s\n", currentFunctionName, currentAction, errorDescription);
        return 1;
    };


    printf("LinkedList Tests Passed.\n");
    return 0;
}