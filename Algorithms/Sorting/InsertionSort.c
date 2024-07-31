#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void insertionSort (int* array, int arraySize, int direction) {
    for (int i = 1; i < arraySize; i++) {
        for (int j = 0; j < i; j++) {
            if (direction == 2 && array[i] > array[j]) {
                int temp = array[i];//store the item to be inserted
                for (int k = i; k > j; k--) { //shift items to the right
                    array[k] = array[k-1];
                }
                array[j] = temp; //insert the item in the proper place
            }
            if (direction == 1 && array[i] < array[j]) {
                int temp = array[i]; //store the item to be inserted
                for (int k = i; k > j; k--) { //shift items to the right
                    array[k] = array[k-1];
                }
                array[j] = temp; //insert the item in the proper place
            }
        }
    }
}

int main (int) {
    int array[6] = {64, 25, 12, 22, 11, 100};

    insertionSort(array, 6, 2);

    for (int i = 0; i < 6; i++) {
        printf("%d\n", *(array + i));
    }
}