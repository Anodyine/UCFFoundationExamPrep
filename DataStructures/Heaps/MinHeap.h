#ifndef MINHEAP_H
#define MINHEAP_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MinHeap {
    int* elements;
    int capacity;
    int size;
} MinHeap;

MinHeap* new_MinHeap (int capacity);
void MinHeap_Heapify (MinHeap* heap, int index);
void MinHeap_Build (MinHeap* heap, int array[], int length);
void MinHeap_Insert (MinHeap* heap, int value);

void MinHeap_Destroy (MinHeap* heap);

#endif