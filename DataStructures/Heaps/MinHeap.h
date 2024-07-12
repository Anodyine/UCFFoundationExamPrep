#ifndef MINHEAP_H
#define MINHEAP_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../BinaryTrees/BinaryTree.h"

typedef struct MinHeap {
    int* elements;
    int capacity;
    int size;
} MinHeap;

MinHeap* new_MinHeap (int* array, int capacity, int size);


#endif