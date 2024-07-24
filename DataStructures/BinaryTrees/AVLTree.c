#include "AVLTree.h"

void AVLTree_SetHeight(AVLTreeNode* currentNode) {
    int newHeight = 1;
    if (currentNode->left != NULL)
        newHeight = currentNode->left->height + 1;
    if (currentNode->right != NULL && currentNode->right->height + 1 > newHeight) {
        newHeight = currentNode->right->height + 1;
    }
    currentNode->height = newHeight;
    if (currentNode->parent != NULL) {
        AVLTree_SetHeight(currentNode->parent);
    }
}

AVLTreeNode* new_AVLTreeNode (int value, AVLTreeNode* parent) {
    AVLTreeNode* node = malloc(sizeof(AVLTreeNode));
    node->value = value;
    node->height = 1;
    node->parent = parent;
    node->right = NULL;
    node->left = NULL;

    return node;
}

AVLTreeNode* AVLTree_RotateRight (AVLTreeNode* currentNode) {
    if (currentNode->left == NULL || currentNode->left->right == NULL) {
        return currentNode;
    }
    // Store the value that will be the new left node and update the left node
    AVLTreeNode* newLeft = currentNode->left->right;
    AVLTreeNode* newRoot = currentNode->left;
    newRoot->right = currentNode;
    newRoot->parent = currentNode->parent;

    // Update the current node
    currentNode->parent = newRoot;
    currentNode->left = newLeft;

    if (newRoot->parent != NULL) {
        if (newRoot->parent->left == currentNode){
            newRoot->parent->left = newRoot;
        }
        if (newRoot->parent->right == currentNode){
            newRoot->parent->right = newRoot;
        }
    }
    AVLTree_SetHeight(currentNode);
    // Update the parent of the new left node
    if (currentNode->left != NULL) {
        currentNode->left->parent = currentNode;
    }

    return newRoot;
}

AVLTreeNode* AVLTree_RotateLeft (AVLTreeNode* currentNode) {
    if (currentNode->right == NULL || currentNode->right->left == NULL) {
        return currentNode;
    }
    // Store the value that will be the new left node and update the left node
    AVLTreeNode* newRight = currentNode->right->left;
    AVLTreeNode* newRoot = currentNode->right;
    newRoot->left = currentNode;
    newRoot->parent = currentNode->parent;

   // Update the current node
    currentNode->parent = newRoot;
    currentNode->right = newRight;

    if (newRoot->parent != NULL) {
        if (newRoot->parent->left == currentNode){
            newRoot->parent->left = newRoot;
        }
        if (newRoot->parent->right == currentNode){
            newRoot->parent->right = newRoot;
        }
    }

    AVLTree_SetHeight(currentNode);
    // Update the parent of the new right node
    if (currentNode->right != NULL) {
        currentNode->right->parent = currentNode;
    }

    return newRoot;
}

AVLTreeNode* AVLTree_Balance (AVLTreeNode* currentNode, int value) {
    if (currentNode == NULL) {
        return NULL;
    }

    int balanceFactor;
    if (currentNode->left == NULL && currentNode->right != NULL) {
        balanceFactor = 0 - currentNode->right->height;
    }

    if (currentNode->right == NULL && currentNode->left != NULL) {
        balanceFactor = currentNode->left->height;
    }

    if (currentNode->right != NULL && currentNode->left != NULL) {
        balanceFactor = currentNode->left->height - currentNode->right->height;
    }

    AVLTreeNode* newRoot = currentNode;
    if (currentNode->left != NULL) {
        if (balanceFactor > 1 && value < currentNode->left->value) {
            newRoot = AVLTree_RotateRight(currentNode);
        }
        if (balanceFactor < -1 && value < currentNode->left->value) {
            currentNode->right = AVLTree_RotateRight(currentNode->right);
            newRoot = AVLTree_RotateLeft(currentNode);
        }
    } else {
        if (currentNode->right != NULL && balanceFactor < -1) {
            currentNode->right = AVLTree_RotateRight(currentNode->right);
            newRoot = AVLTree_RotateLeft(currentNode);
        }
    }
    if (currentNode->right != NULL) {
        if (balanceFactor < -1 && value > currentNode->right->value) {
            newRoot = AVLTree_RotateLeft(currentNode);
        } 
        if (balanceFactor > 1 && value > currentNode->right->value) {
            currentNode->left = AVLTree_RotateLeft(currentNode->left);
            newRoot = AVLTree_RotateRight(currentNode);
        }
    } 
    else {
        if (currentNode->left != NULL && balanceFactor > 1) {
            currentNode->left = AVLTree_RotateLeft(currentNode->left);
            newRoot = AVLTree_RotateRight(currentNode);
        }
    }

    if (newRoot->parent != NULL){
        return AVLTree_Balance(newRoot->parent, value);
    } else {
        return newRoot;
    }
}

AVLTreeNode* AVLTree_Insert (AVLTreeNode* currentNode, int value) {
    if (currentNode->value == value) {
        printf("The value, %d, is already present in the tree.\n", value);
        return NULL;
    }

    if (currentNode->left == NULL && currentNode->right == NULL) { // if we are at a leaf
        if (currentNode->value < value) {
            currentNode->right = new_AVLTreeNode(value, currentNode);
            AVLTree_SetHeight(currentNode);
        } else {
            currentNode->left = new_AVLTreeNode(value, currentNode);
            AVLTree_SetHeight(currentNode);
        }
        return AVLTree_Balance(currentNode, value);
    }

    AVLTreeNode* newNode = currentNode;
    if (currentNode->value < value) {
        if (currentNode->right != NULL) {
            newNode = AVLTree_Insert(currentNode->right, value);
        } else {
            currentNode->right = new_AVLTreeNode(value, currentNode);
            AVLTree_SetHeight(currentNode);
            return AVLTree_Balance(currentNode, value);
        }
    }

    if (currentNode->value > value) {
        if (currentNode->left != NULL) {
            newNode = AVLTree_Insert(currentNode->left, value);
        } else {
            currentNode->left = new_AVLTreeNode(value, currentNode);
            AVLTree_SetHeight(currentNode);
            return AVLTree_Balance(currentNode, value);
        }
    }

    while (newNode->parent != NULL) {
        newNode = newNode->parent;
    }
    return newNode;
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
    AVLTreeNode* root = new_AVLTreeNode(8, NULL);
    root = AVLTree_Insert (root, 4);
    root = AVLTree_Insert (root, 10);
    root = AVLTree_Insert (root, 3);
    root = AVLTree_Insert (root, 5);
    root = AVLTree_Insert (root, 6);
    root = AVLTree_Insert (root, 7);

    char positionString[500] = "Root";
    PrintTree(root, positionString);
}