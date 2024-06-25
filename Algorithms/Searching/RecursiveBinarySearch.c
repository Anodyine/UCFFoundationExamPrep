#include <stdio.h>

int binarySearch (int* sortedArray, int target, int lowIndex, int highIndex) {
    if (lowIndex > highIndex) {
        return -1;
    }

    int midIndex = (highIndex + lowIndex) / 2;
    if (target > sortedArray[midIndex]) {
        return binarySearch(sortedArray, target, lowIndex + 1, highIndex);
    }

    if (target < sortedArray[midIndex]) {
        return binarySearch(sortedArray, target, lowIndex, highIndex - 1);
    }

    return midIndex;
}

int main (int) {
    int array[5] = {11, 12, 22, 25, 64};

    printf("The target is at index: %d", binarySearch(array, 23, 0, 4));
}