#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
    void* data;
    struct _Node* next;
    struct _Node* previous;
} Node;

typedef struct {
    int length;
    char typeName[32];
    int typeSize;
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* new_LinkedList (char* typeName, int typeSize);
int LinkedList_Add (LinkedList* list, void* data);
void* LinkedList_GetFirst (LinkedList* list);
void* LinkedList_GetLast (LinkedList* list);
void* LinkedList_GetByIndex (LinkedList* list, int index);
int LinkedList_RemoveByIndex (LinkedList* list, int index);
int LinkedList_Destroy (LinkedList* list);

#endif