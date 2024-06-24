#include <stdio.h>

int binarySearch (int* sortedArray, int size, int target) {
    int resultIndex = -1;
    int highIndex = size - 1;
    int lowIndex = 0;
    int midIndex;
    while(lowIndex <= highIndex) {
        midIndex = (highIndex + lowIndex) / 2;
        if (*(sortedArray + midIndex) == target) {
            return midIndex;
        }

        if (*(sortedArray + midIndex) < target) {
            lowIndex = midIndex + 1;
        } else {
            highIndex = midIndex - 1;
        }
    }
    
    return -1;
}

int main (int) {
    int array[5] = {11, 12, 22, 25, 64};

    printf("The target is at index: %d", binarySearch(array, 5, 9));
}