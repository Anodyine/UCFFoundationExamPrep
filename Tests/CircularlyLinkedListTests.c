#include "../DataStructures/LinkedLists/CircularlyLinkedList.h"

int main()
{
    Node *head = NULL;
    // Insert items into the singly circular linked list
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    // Print the list
    printf("Singly Circular Linked List: ");
    printList(head);
    return 0;
}