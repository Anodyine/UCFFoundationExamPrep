#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _BinarySearchTreeNode {
    int data;
    struct _BinarySearchTreeNode* left;
    struct _BinarySearchTreeNode* right;
} BinarySearchTreeNode;

void BinarySearchTree_Insert (BinarySearchTreeNode* root, int data);
int BinarySearchTree_Delete (BinarySearchTreeNode* root, int data);
bool BinarySearchTree_Contains (BinarySearchTreeNode* root, int data);

#endif