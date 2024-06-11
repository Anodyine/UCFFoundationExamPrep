#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _StackNode {
    void* data;
    struct _StackNode* next;
} StackNode;

typedef struct {
    int length;
    char typeName[100];
    int typeSize;
    StackNode* head;
} LinkedStack;

LinkedStack* new_LinkedStack (char* typeName, int typeSize);
void LinkedStack_Push (LinkedStack* stack, void* data);
void LinkedStack_RemoveTop (LinkedStack* stack);
void* LinkedStack_Peek (LinkedStack* stack);
bool LinkedStack_IsEmpty (LinkedStack* stack);
void LinkedStack_Destroy (LinkedStack* stack);

#endif