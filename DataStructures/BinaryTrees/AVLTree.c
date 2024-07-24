#include "AVLTree.h"

int AVLTree_GetHeight(AVLTreeNode *node) {
    if (node == NULL)
        return -1;
    else
        return node->height;
}

AVLTreeNode* new_AVLTreeNode (int value) {
    AVLTreeNode* node = malloc(sizeof(AVLTreeNode));

    if (node == NULL)
        printf("Out of space!!!");
    else
    {
        node->value = value;
        node->height = 0;
        node->left = node->right = NULL;
    }

    return node;
}

void AVLTree_SetHeight(AVLTreeNode* currentNode) {
    int newHeight = 0;
    int leftHeight = AVLTree_GetHeight(currentNode->left);
    int rightHeight = AVLTree_GetHeight(currentNode->right);

    if (leftHeight + 1 > newHeight) {
        newHeight = leftHeight + 1;
    }
    if (rightHeight + 1 > newHeight) {
        newHeight = rightHeight + 1;
    }
    currentNode->height = newHeight;
}

AVLTreeNode* AVLTree_RotateRight(AVLTreeNode * initialRoot) {
    AVLTreeNode* newRoot = initialRoot->left;
    initialRoot->left = newRoot->right;
    newRoot->right = initialRoot;

    AVLTree_SetHeight(initialRoot);
    AVLTree_SetHeight(newRoot);
    return newRoot; 
}

AVLTreeNode* AVLTree_RotateLeft(AVLTreeNode * initialRoot) {
    AVLTreeNode* newRoot = initialRoot->right;
    initialRoot->right = newRoot->left;
    newRoot->left = initialRoot;

    AVLTree_SetHeight(initialRoot);
    AVLTree_SetHeight(newRoot);
    return newRoot; 
}

AVLTreeNode* AVLTree_DoubleRotateLeftRight(AVLTreeNode* node)
{
    node->left = AVLTree_RotateLeft(node->left);
    return AVLTree_RotateRight(node);
}

AVLTreeNode* AVLTree_DoubleRotateRightLeft(AVLTreeNode* node)
{
    node->right = AVLTree_RotateRight(node->right);
    return AVLTree_RotateLeft(node);
}

AVLTreeNode* AVLTree_Insert(AVLTreeNode* node, int value) {
    if (node == NULL) {
        node = new_AVLTreeNode(value);
    }
    else if (value < node->value) {
        node->left = AVLTree_Insert(node->left, value);
        if (AVLTree_GetHeight(node->left) - AVLTree_GetHeight(node->right) > 1) {
            if (value < node->left->value) {
                node = AVLTree_RotateRight(node);
            } else {
                node = AVLTree_DoubleRotateLeftRight(node);
            }
        }
    }
    else if (value > node->value) {
        node->right = AVLTree_Insert(node->right, value);
        if (AVLTree_GetHeight(node->left) - AVLTree_GetHeight(node->right) < -1) {
            if (value > node->right->value) {
                node = AVLTree_RotateLeft(node);
            } else {
                node = AVLTree_DoubleRotateRightLeft(node);
            }
        }
    }

    AVLTree_SetHeight(node);
    return node;
}

void PrintTree(AVLTreeNode *current_ptr, char* positionString) {
    if (current_ptr == NULL) {
        return;
    }

    printf("%s: %d, Height: %d \n", positionString, current_ptr->value, current_ptr->height);

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

int main (int input) {
    printf("Testing single right rotate:\n");
    AVLTreeNode* root = new_AVLTreeNode(8);
    root = AVLTree_Insert (root, 7);
    root = AVLTree_Insert (root, 6);
    root = AVLTree_Insert (root, 5);
    root = AVLTree_Insert (root, 4);

    char positionString[500] = "Root";
    PrintTree(root, positionString);

    printf("\nTesting single left rotate:\n");
    root = new_AVLTreeNode(8);
    root = AVLTree_Insert (root, 9);
    root = AVLTree_Insert (root, 10);
    root = AVLTree_Insert (root, 11);
    root = AVLTree_Insert (root, 12);

    strcpy(positionString, "Root");
    PrintTree(root, positionString);

    printf("\nTesting double rotate left right:\n");
    root = new_AVLTreeNode(8);
    root = AVLTree_Insert (root, 1);
    root = AVLTree_Insert (root, 2);
    root = AVLTree_Insert (root, 3);
    root = AVLTree_Insert (root, 4);

    strcpy(positionString, "Root");
    PrintTree(root, positionString);

    printf("\nTesting double rotate right left:\n");
    root = new_AVLTreeNode(8);
    root = AVLTree_Insert (root, 12);
    root = AVLTree_Insert (root, 11);
    root = AVLTree_Insert (root, 10);
    root = AVLTree_Insert (root, 9);

    strcpy(positionString, "Root");
    PrintTree(root, positionString);
}