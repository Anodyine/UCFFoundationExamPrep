#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void print(int *A, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
}

int countPermutations(int *perm, int *used, int k, int n)
{
    if (k == n)
    {
        printf("Counted this permutation: ");
        print(perm, k);
        printf("\n");
        return 1; // if k reaches the length return 1
    }

    int i;
    int total = 0;
    for (i = 0; i < n; i++)
    {
        if (!used[i])
        {                // if i was not used
            used[i] = 1; // mark that it is used
            perm[k] = i; // transfer i to the the perm array at kth position
            printf("Adding another version of countPermutation of the stack to count all of the permutations that start with: ");
            print(perm, k + 1);
            printf("\n");
            int res = countPermutations(perm, used, k + 1, n); // increase k and grow further
            printf("countPermutations returned with result: %d\n", res);
            total += res;
            used[i] = 0;                                          // unmark i for next process.
        }
    }

    printf("countPermutations has finished counting all permutations that start with: ");
    print(perm, k);
    printf("\n");
    return total;
}

int main(void)
{
    int perm[SIZE] = {0}; // to build and store the permutation
    int used[SIZE] = {0}; // tracking which index is used

    printf("Total permutations: %d", countPermutations(perm, used, 0, SIZE));

    return 0;
}