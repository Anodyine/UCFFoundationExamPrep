#include "LinkedList.h"

/*
    This generic linked list stores a list of void pointers. To access the data, is required to type cast the return value of LinkedList_GetByIndex to 
    a pointer to whichever data type you used when you created the list. To help with that, a typeName property is provided in case you are working with 
    multiple types of lists and need to differentiate between them. The list also has a typeSize property that tracks the size that each data item 
    will have in memory. The author recommeneds to only modify the list through the given functions and not to modify the properties typeSize, typeName,
    length, head, or tail directly. Reading the properties should not cause issues.

    The list is zero indexed. The first item you add with LinkedList_Add will be at index 0, the second one will be at index 1, etc.
*/

LinkedList* new_LinkedList (char* typeName, int typeSize) {
    if (strlen(typeName) > 32) {
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

    /* Update Pointers */
    newNode->next = list->head;
    newNode->previous = NULL;
    if (list->head != NULL) {
        list->head->previous = newNode;
    }
    list->head = newNode;
    if (list->tail == NULL) {
        list->tail = newNode;
    }

    /* Copy Data */
    newNode->data = malloc(list->typeSize);
    memcpy(newNode->data, data, list->typeSize);

    /* Increase Length */
    list->length++;

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
        printf("You tried to access an index that is greater than the length of the List minus 1.\n");
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

int LinkedList_RemoveByIndex (LinkedList* list, int index) { 
    if (index > list->length - 1) {
        printf("You tried to access an index that is greater than the length of the List.\n");
        return -1;
    }

    if (index < 0) {
        printf("You tried to access an index that is less than 0.\n");
        return -1;
    }

    Node* cursor = list->head;
    for (int i = 0; i < list->length - 1 - index; i++) {
        cursor = cursor->next;
    }

    free(cursor->data);

    if (cursor->previous == NULL) {
        list->head = cursor->next;
    } else {
        cursor->previous->next = cursor->next;
    }

    if (cursor->next == NULL) {
        list->tail = cursor->previous;
    } else {
        cursor->next->previous = cursor->previous;
    }

    free(cursor);
    list->length--;

    return 0;
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
