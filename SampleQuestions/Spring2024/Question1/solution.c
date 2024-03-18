#include <stdio.h>
#include <stdlib.h>

int** triangularSum (int* base, int n) {
    // Allocated memory for a pointer to each array
    int** result = malloc(n * sizeof(int*));
    // Allocated memory for each element in the base array
    result[0] = malloc(n * sizeof(int));
    for (int i=0; i < n; i++) {
        result[0][i] = base[i];
    }

    for (int i = 1; i < n; i++) {
        // Allocated memory for each element in one of the smaller arrays
        result[i] = malloc((n - i) * sizeof(int));
        for (int j = 0; j < n - i; j++) {
            result[i][j] = result[i - 1][j] + result[i - 1][j + 1];
        }
    }

    return result;
}

int main (int) {
    int base[5] = {1, 2, 3, 4, 5};
    int** result = triangularSum(base, 5);

    for (int i = 0; i < 5; i++) {
        printf("result[%d] = { ", i);
        for (int j = 0; j < 5-i; j++) {
            printf("%d ", result[i][j]);
        }
        printf("}\n");
    }

    for (int i = 0; i < 5; i++) {
        free(result[i]);
    }

    free(result);
}