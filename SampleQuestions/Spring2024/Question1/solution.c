#include <stdio.h>
#include <stdlib.h>

int** triangularSum (int* base, int n) {
    int** result = malloc(n * sizeof(int*));
    result[0] = base;
    for (int i = 1; i < n; i++) {
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