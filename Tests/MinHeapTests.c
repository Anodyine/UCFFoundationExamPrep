#include "../DataStructures/Heaps/MinHeap.h"

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main (int input) {
    int arr[] = {1, 17, 3, 12, 11, 13, 5, 6, 7, 8, 2};

    printf("Original array: ");
    printArray(arr, 11);

    Heapsort (arr, 11);

    printf("Sorted array: ");
    printArray(arr, 11);

    return 0;
}
