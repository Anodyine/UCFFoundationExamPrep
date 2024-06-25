#include <stdio.h>

int findMatchingNumbers(int array1[], int array2[], int result[], int size) {
    int searchResult;
    int numMatches = 0;
    int i = 0;
    int j = 0;
    while (i < size && j < size) {
        if (array1[i] > array2[j]) {
            j++;
        } 

        if (array1[i] < array2[j]) {
            i++;
        }

        if (array1[i] == array2[j]) {
            result[numMatches] = array1[i];
            numMatches++;
            i++;
            j++;
        }
    }

    return numMatches;
}

int main (int) {
    int array1[5] = {11, 12, 22, 25, 64};
    int array2[5] = {10, 13, 22, 24, 25};
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