#ifndef AVLTREE_H
#define AVLTREE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _AVLTreeNode {
    int value;
    struct _AVLTreeNode *left;
    struct _AVLTreeNode *right;
    int height;
} AVLTreeNode;

AVLTreeNode* new_AVLTreeNode (int value);
AVLTreeNode* AVLTree_Insert(AVLTreeNode* node, int value);

#endif