#include <stdio.h>
#include <stdlib.h>

typedef struct node_s { 
    int data; 
    struct node_s* next; 
} node_t; 
 
node_t * moveHeadNearTail(node_t * head) {  
    if (head == NULL) {
        return NULL;
    }

    node_t *cursor = head;
    node_t *previousCursor = NULL;
    while (cursor->next != NULL) {
        previousCursor = cursor;
        cursor = cursor->next;
    }

    node_t *newHead = head->next;
    head->next = cursor;
    previousCursor->next = head;

    return newHead;
}

void printMyList (node_t *head) {
    node_t *cursor = head;
    while (cursor != NULL) {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }

    printf("\n");

    return;
}

int main (int) {
    node_t * head = malloc(sizeof(node_t));

    node_t * node2 = malloc(sizeof(node_t));
    node_t * node3 = malloc(sizeof(node_t));
    node_t * node4 = malloc(sizeof(node_t));

    head->data = 1;
    node2->data = 7;
    node3->data = 5;
    node4->data = 2;

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    printf("Before moveHeadnearTail: \n");
    printMyList (head);
    
    head = moveHeadNearTail(head);

    printf("After moveHeadnearTail: \n");
    printMyList (head);

    free(head);
    free(head->next);
    free(head->next->next);
    free(head->next->next->next);
}