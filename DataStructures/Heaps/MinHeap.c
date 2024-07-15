#include "MinHeap.h"

MinHeap* new_MinHeap (int capacity) {
    MinHeap* newHeap = malloc(sizeof(MinHeap));
    newHeap->elements = malloc(sizeof(int) * capacity);
    newHeap->capacity = capacity;
    newHeap->size = 0;

    return newHeap;
}


int MinHeap_GetLeftChildIndex (int index) {
    return 2*(index + 1) - 1;
}

int MinHeap_GetRightChildIndex (int index) {
    return 2*(index + 1);
}

void MinHeap_Build (MinHeap* heap, int array[], int length) {
    heap->size = length;
    memcpy(heap->elements, array, sizeof(int) * length);

    for (int i = length/2 - 1; i >= 0; i--) {
        MinHeap_Heapify(heap, i);
    }
}

void MinHeap_Heapify (MinHeap* heap, int index) {
    int leftIndex = MinHeap_GetLeftChildIndex(index);
    int rightIndex = MinHeap_GetRightChildIndex(index);
    int indexOfSmallest = index;

    if (leftIndex < heap->size && heap->elements[leftIndex] < heap->elements[indexOfSmallest]) {
        indexOfSmallest = leftIndex;
    }

    if (rightIndex < heap->size && heap->elements[rightIndex] < heap->elements[indexOfSmallest]) {
        indexOfSmallest = rightIndex;
    }

    if (indexOfSmallest != index) {
        int temp = heap->elements[index];
        heap->elements[index] = heap->elements[indexOfSmallest];
        heap->elements[indexOfSmallest] = temp;
        MinHeap_Heapify(heap, indexOfSmallest);
    }
}

void MinHeap_Insert (MinHeap* heap, int value) {
    if (heap->size + 1 >= heap->capacity) {
        printf("Inserting would exceed heap capacity. Insert failed.");
        return;
    }

    for (int i = heap->size; i > 0; i--) {
        heap[i] = heap[i - 1];
    }
    heap->elements[0] = value;
    heap->size++;

    MinHeap_Heapify(heap, 0);
}

void MinHeap_Destroy (MinHeap* heap) {
    free(heap->elements);
    heap->elements = NULL;
    free(heap);
    heap = NULL;
}

void Heapsort (int array[], int length) {
    MinHeap *heap = new_MinHeap(400);
    MinHeap_Build(heap, array, length);
    for (int i = 0; i < length; i++) {
        array[i] = heap->elements[0];
        heap->elements[0] = heap->elements[heap->size - 1];
        heap->size--;
        MinHeap_Heapify(heap, 0);
    }

    MinHeap_Destroy(heap);
}
