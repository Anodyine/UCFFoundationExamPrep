#include <stdio.h>
#include <stdlib.h>
#include "../../../../DataStructures/BinaryTrees/BinaryTree.h"

int sumSingleParents (BinaryTreeNode* node) {
    // if the node was null
    if (node == NULL) {
        return 0;
    }

    // if the node only has a right node
    if ((node->left == NULL && node->right != NULL)) {
        return *(int*)node->data + sumSingleParents(node->right);
    }

    // if the node only has a left node
    if (node->left != NULL && node->right == NULL) {
        return *(int*)node->data + sumSingleParents(node->left);
    }
    
    // if the node has two children
    return sumSingleParents(node->left) + sumSingleParents(node->right);
}

int main (int) {
    int nodeData = 13;
    BinaryTreeNode* root = new_BinaryTreeNode("int", sizeof(int), &nodeData);

    nodeData = 4;
    root->left = new_BinaryTreeNode("int", sizeof(int), &nodeData);
    nodeData = 25;
    root->right = new_BinaryTreeNode("int", sizeof(int), &nodeData);

    nodeData = 3;
    root->left->left = new_BinaryTreeNode("int", sizeof(int), &nodeData);
    nodeData = 8;
    root->left->right = new_BinaryTreeNode("int", sizeof(int), &nodeData);

    nodeData = 20;
    root->right->left = new_BinaryTreeNode("int", sizeof(int), &nodeData);
    nodeData = 30;
    root->right->right = new_BinaryTreeNode("int", sizeof(int), &nodeData);

    nodeData = 2;
    root->left->left->left = new_BinaryTreeNode("int", sizeof(int), &nodeData);

    nodeData = 9;
    root->left->left->left->left = new_BinaryTreeNode("int", sizeof(int), &nodeData);

    nodeData = 5;
    root->left->right->left = new_BinaryTreeNode("int", sizeof(int), &nodeData);

    nodeData = 22;
    root->right->left->right = new_BinaryTreeNode("int", sizeof(int), &nodeData);

    printf(
        "Example Tree:\n%d\n%d %d\n%d %d | %d %d\n%d | %d | %d\n%d\n", 
        *(int*)root->data, 
        *(int*)root->left->data, 
        *(int*)root->right->data,
        *(int*)root->left->left->data, 
        *(int*)root->left->right->data, 
        *(int*)root->right->left->data, 
        *(int*)root->right->right->data,
        *(int*)root->left->left->left->data,
        *(int*)root->left->right->left->data,
        *(int*)root->right->left->right->data,
        *(int*)root->left->left->left->left->data
    );

    int result = sumSingleParents(root);

    printf("Result of sumSingleParents: %d\n", result);

    return 0;
}