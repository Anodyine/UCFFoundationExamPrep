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

int findMatchingNumbers(int array1[], int array2[], int result[], int size) {
    int numMatches = 0;
    for (int i = 0; i < size; i++) {
        searchResult = binarySearch(array2, size, array1[i]);
        if (searchResult != -1) {
            result[numMatches] = array1[i];
            numMatches++;
        }
    }

    return numMatches;
}

int main (int) {
    int array1[5] = {11, 12, 22, 25, 64};
    int array2[5] = {10, 22, 23, 24, 65};
    int result[5];
    int numMatches = findMatchingNumbers(array1, array2, result, 5);

    if (numMatches == 0) {
        printf("No matches were found.");
    } else {
        printf("The following numbers appear in both lists: ");
        for (int i = 0; i < numMatches; i++){
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}