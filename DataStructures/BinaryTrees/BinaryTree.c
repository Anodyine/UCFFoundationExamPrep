#include "BinaryTree.h"
#include <string.h>

BinaryTreeNode* new_BinaryTreeNode (char* typeName, int typeSize, void* data) {
    BinaryTreeNode* newNode = malloc(sizeof(BinaryTreeNode));

    strcpy(newNode->typeName, typeName);
    newNode->typeSize = typeSize;

    newNode->data = malloc(typeSize);
    memcpy(newNode->data, data, newNode->typeSize);

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void BinaryTreeNode_SetData (BinaryTreeNode* node, void* data) {
    memcpy(node->data, data, node->typeSize);
    return;
}
