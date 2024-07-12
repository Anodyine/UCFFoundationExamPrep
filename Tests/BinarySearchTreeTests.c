#include "../DataStructures/BinaryTrees/BinarySearchTree.h"

void PrintTree(BinarySearchTreeNode *current_ptr, char* positionString) {
    if (current_ptr == NULL) {
        return;
    }

    printf("%s: %d \n", positionString, current_ptr->data);

    char leftPosStr[500];
    strcpy(leftPosStr, positionString);
    strcat(leftPosStr, "Left");
    PrintTree(current_ptr->left, leftPosStr);
    char rightPosStr[500];
    strcpy(rightPosStr, positionString);
    strcat(rightPosStr, "Right");
    PrintTree(current_ptr->right, rightPosStr);

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

    PrintTree(root, positionString);
}