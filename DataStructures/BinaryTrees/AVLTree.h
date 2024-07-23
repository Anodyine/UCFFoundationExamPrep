#ifndef AVLTREE_H
#define AVLTREE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _AVLTreeNode {
    int value;
    int height;
    struct _AVLTreeNode* parent;
    struct _AVLTreeNode* left;
    struct _AVLTreeNode* right;
} AVLTreeNode;

AVLTreeNode* new_AVLTreeNode (int value, AVLTreeNode* parent);
AVLTreeNode* AVLTree_Insert (AVLTreeNode* root, int value);
int AVLTree_DeleteByValue (AVLTreeNode* root, int value);
bool AVLTree_Contains (AVLTreeNode* root, int value);
void AVLTreeNode_Destroy (AVLTreeNode* root);

#endif