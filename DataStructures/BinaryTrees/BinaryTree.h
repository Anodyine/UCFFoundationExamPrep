#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _BinaryTreeNode {
    char typeName[100];
    int typeSize;
    void* data;
    struct _BinaryTreeNode* left;
    struct _BinaryTreeNode* right;
} BinaryTreeNode;

BinaryTreeNode* new_BinaryTreeNode (char* typeName, int typeSize, void* data);
void BinaryTreeNode_SetData (BinaryTreeNode* node, void* data);
void BinaryTreeNode_Destroy (BinaryTreeNode* node);

#endif