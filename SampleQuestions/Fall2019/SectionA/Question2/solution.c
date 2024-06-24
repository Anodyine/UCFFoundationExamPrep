#include <stdlib.h>
#include <stdio.h>

typedef struct node { 
    char letter; 
    struct node* next; 
} node; 
 
int length(node* head); 
 
char* toCString(node * head) {
    if (head == NULL) {
        return "\0";
    }

    int len = length(head);
    char* result = malloc(sizeof(char) * (len + 1));
    node* cursor = head;
    int index = 0;

    *(result + index) = head->letter;

    while (cursor->next != NULL) {
        cursor = cursor->next;
        index++;
        *(result + index) = cursor->letter;
    }

    *(result + index + 1) = '\0';
    
    return result;
}

int length (node* head) {
    int result = 1;
    node* cursor = head;

    while (cursor->next != NULL) {
        result++;
        cursor = cursor->next;
    }

    return result;
}

int main (int) {
    node* head = malloc(sizeof(node));
    head->letter = 'h';
    node* node1 = malloc(sizeof(node));
    node1->letter = 'e';
    node1->next = NULL;
    head->next = node1;

    char* result = toCString(head);

    printf("The result is: %s", result);
}