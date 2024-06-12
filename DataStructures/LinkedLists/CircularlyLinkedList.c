#include "CircularlyLinkedList.h"

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of a singly circular linked list
void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        // List is empty, initialize the new node to point to itself
        *head = newNode;
        newNode->next = newNode;
    }
    else
    {
        // Traverse to the last node
        Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        // Insert the new node at the end
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Function to print the singly circular linked list
void printList(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

// TODO: Implement destroyList
