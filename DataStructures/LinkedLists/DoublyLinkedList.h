#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _DoublyLinkedNode {
    void* data;
    struct _DoublyLinkedNode* next;
    struct _DoublyLinkedNode* previous;
} DoublyLinkedNode;

typedef struct {
    int length;
    char typeName[100];
    int typeSize;
    DoublyLinkedNode* head;
    DoublyLinkedNode* tail;
} DoublyLinkedList;

DoublyLinkedList* new_LinkedList (char* typeName, int typeSize);
int LinkedList_Add (DoublyLinkedList* list, void* data);
void* LinkedList_GetFirst (DoublyLinkedList* list);
void* LinkedList_GetLast (DoublyLinkedList* list);
void* LinkedList_GetByIndex (DoublyLinkedList* list, int index);
int LinkedList_RemoveByIndex (DoublyLinkedList* list, int index);
int LinkedList_Destroy (DoublyLinkedList* list);

#endif