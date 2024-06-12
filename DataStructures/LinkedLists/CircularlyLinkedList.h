
#ifndef CIRCULARLYLINKEDLIST_H
#define CIRCULARLYLINKEDLIST_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Define the Node structure for a singly circular linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
void insertAtEnd(Node **head, int data);
void printList(Node *head);

#endif