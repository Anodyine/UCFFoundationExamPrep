#include "BinarySearchTree.h"

void BinarySearchTree_Insert (BinarySearchTreeNode* root, int data) {
    if (root->data == data) {
        printf("The value, %d, is already present in the tree.\n", data);
        return;
    }

    if (root->left == NULL && root->right == NULL) { // if we are at a leaf
        BinarySearchTreeNode* newNode = malloc(sizeof(BinarySearchTreeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        if (root->data < data) {
            root->right = newNode;
        } else {
            root->left = newNode;
        }
        return;
    }

    if (root->data < data) {
        if (root->right != NULL) {
            BinarySearchTree_Insert(root->right, data);
        } else {
            BinarySearchTreeNode* newNode = malloc(sizeof(BinarySearchTreeNode));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            root->right = newNode;
        }
    }

    if (root->data > data) {
        if (root->left != NULL) {
            BinarySearchTree_Insert(root->left, data);
        } else {
            BinarySearchTreeNode* newNode = malloc(sizeof(BinarySearchTreeNode));
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            root->left = newNode;
        }
    }
}

// int BinarySearchTree_Delete (BinaryTreeNode* root, int data);
// bool BinarySearchTree_Contains (BinaryTreeNode* root, int data);