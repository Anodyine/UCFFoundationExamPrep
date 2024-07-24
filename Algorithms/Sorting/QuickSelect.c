#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low >= high) { // if low has reached high, we have found our element
        return arr[low];
    }

    int pivotIndex = partition (arr, low, high);
    if (k-1 == pivotIndex) { // if partition returns this value, we have found our element
        return arr[pivotIndex];
    } else if (pivotIndex > k-1) {
        return quickSelect(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sortedIndexTarget = 6;
    int result = quickSelect(arr, 0, n - 1, sortedIndexTarget);
    printf("The value of the %dth smallest element is: %d", sortedIndexTarget, result);
    return 0;
}
