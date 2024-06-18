#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void selectionSort (int* array, int arraySize, int direction) {
    for (int i = 0; i < arraySize; i++) {
        int swapIndex = i;
        for (int j = i + 1; j < arraySize; j++) {
            if (direction == 1 && *(array + swapIndex) > *(array + j)) {
                swapIndex = j;
            }

            if (direction == 2 && *(array + swapIndex) < *(array + j)) {
                swapIndex = j;
            }
        }

        if (swapIndex != i) {
            int temp = *(array + i);
            *(array + i) = *(array + swapIndex);
            *(array + swapIndex) = temp;
        }
    }
}

int main (int) {
    int array[5] = {64, 25, 12, 22, 11};

    selectionSort(array, 5, 2);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", *(array + i));
    }
}