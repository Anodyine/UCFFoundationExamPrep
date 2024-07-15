#include "../DataStructures/Heaps/MinHeap.h"

int main (int input) {
    int arr[] = {12, 11, 13, 5, 6, 7, 8, 2};

    MinHeap *heap = new_MinHeap(400);
    MinHeap_Build(heap, arr, 8);

    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->elements[i]);
    }

    return 0;
}
