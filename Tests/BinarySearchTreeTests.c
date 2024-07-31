#include "../DataStructures/BinaryTrees/BinarySearchTree.h"
#include "../DataStructures/LinkedLists/DoublyLinkedList.h"

void PrintTreeBreadthFirst(BinarySearchTreeNode *current_ptr) {
    if (current_ptr == NULL) {
        return;
    }

    DoublyLinkedList* myList = new_LinkedList("BSTNode", sizeof(BinarySearchTreeNode*));

    LinkedList_Add(myList, &current_ptr);
    printf("%d ", current_ptr->data);
    do 
    {
        current_ptr = (*(BinarySearchTreeNode**)LinkedList_GetFirst(myList));
        
        if (current_ptr->left != NULL) {
            printf("%d ", current_ptr->left->data);
            if (current_ptr->left->left != NULL || current_ptr->left->right != NULL )
                LinkedList_Add(myList, &(current_ptr->left));
        }
        if (current_ptr->right != NULL) {
            printf("%d ", current_ptr->right->data);
            if (current_ptr->right->left != NULL || current_ptr->right->right != NULL )
                LinkedList_Add(myList, &(current_ptr->right));
        }

        LinkedList_RemoveFirst(myList);
    } while (myList->length > 0);

    return;
}

void PrintTreeDepthFirst(BinarySearchTreeNode *current_ptr, char* positionString) {
    if (current_ptr == NULL) {
        return;
    }

    printf("%s: %d \n", positionString, current_ptr->data);

    char leftPosStr[500];
    strcpy(leftPosStr, positionString);
    strcat(leftPosStr, "Left");
    PrintTreeDepthFirst(current_ptr->left, leftPosStr);
    char rightPosStr[500];
    strcpy(rightPosStr, positionString);
    strcat(rightPosStr, "Right");
    PrintTreeDepthFirst(current_ptr->right, rightPosStr);

    return;
}

int main (int) {
    BinarySearchTreeNode *root = malloc(sizeof(BinarySearchTreeNode));
    root->data = 6;
    root->left = NULL;
    root->right = NULL;

    char positionString[500] = "Root";

    BinarySearchTree_Insert(root, 9);
    BinarySearchTree_Insert(root, 4);
    BinarySearchTree_Insert(root, 1);
    BinarySearchTree_Insert(root, 11);
    BinarySearchTree_Insert(root, 8);
    BinarySearchTree_Insert(root, 3);
    BinarySearchTree_Insert(root, 5);

    PrintTreeDepthFirst(root, positionString);
    PrintTreeBreadthFirst(root);
}