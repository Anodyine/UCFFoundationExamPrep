#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void bubbleSort (int* array, int arraySize, int direction) {
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < arraySize; j++) {
            if (direction == 2 && *(array + i) > *(array + j)) {
                int temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }

            if (direction == 1 && *(array + i) < *(array + j)) {
                int temp = *(array + j);
                *(array + j) = *(array + i);
                *(array + i) = temp;
            }
        }
    }
}

int main (int) {
    int array[5] = {64, 25, 12, 22, 11};

    bubbleSort(array, 5, 1);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", *(array + i));
    }
}