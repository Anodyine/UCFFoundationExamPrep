#ifndef AVLTREE_H
#define AVLTREE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _AVLTreeNode {
    int data;
    struct _AVLTreeNode* left;
    struct _AVLTreeNode* right;
} AVLTreeNode;

AVLTreeNode* new_AVLTreeNode (int data);
void AVLTree_Insert (AVLTreeNode* root, int data);
int AVLTree_DeleteByValue (AVLTreeNode* root, int data);
bool AVLTree_Contains (AVLTreeNode* root, int data);
void AVLTreeNode_Destroy (AVLTreeNode* root);

#endif