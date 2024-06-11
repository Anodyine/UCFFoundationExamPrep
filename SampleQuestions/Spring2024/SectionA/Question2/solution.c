/* Answer: head -> 2 -> 5 -> 8 -> 1 -> 7 */
#include <stdio.h>
#include <stdlib.h>
#include "../../../../DataStructures/LinkedLists/LinkedList.h"

// typedef struct node_s {
//     int data;
//     struct node_s * nextptr;
// } node_t;

// void whatDoYouDo(node_t * head){
//     node_t * temp = head;
//     node_t * temp2 = head->nextptr;
//     int a;
//     while (temp->nextptr != NULL) {
//         a = temp->data;
//         temp->data = temp2->data;
//         temp2->data = a;
//         temp = temp->nextptr;
//         if(temp->nextptr != NULL){
//             temp = temp->nextptr;
//             temp2 = temp->nextptr;
//         }
//     }
// }

void whatDoYouDo2(Node* head) {
    Node * temp = head;
    Node * temp2 = head->next;
    int a;
    while (temp->next != NULL) {
        a = *(int*)temp->data;
        *(int*)temp->data = *(int*)temp2->data;
        *(int*)temp2->data = a;
        temp = temp->next;
        if(temp->next != NULL){
            temp = temp->next;
            temp2 = temp->next;
        }
    }
}

int main (int) {
    LinkedList* myList = new_LinkedList("int", sizeof(int));

    int* temp = malloc(sizeof(int));
    *temp = 7;
    LinkedList_Add(myList, temp);
    *temp = 8;
    LinkedList_Add(myList, temp);
    *temp = 1;
    LinkedList_Add(myList, temp);
    *temp = 2;
    LinkedList_Add(myList, temp);
    *temp = 5;
    LinkedList_Add(myList, temp);

    whatDoYouDo2(myList->head);

    printf(
        "%d -> %d -> %d -> %d -> %d", 
        *(int*)myList->head->data,
        *(int*)myList->head->next->data,
        *(int*)myList->head->next->next->data,
        *(int*)myList->head->next->next->next->data,
        *(int*)myList->head->next->next->next->next->data
        );
    LinkedList_Destroy(myList);
    return 0;
}