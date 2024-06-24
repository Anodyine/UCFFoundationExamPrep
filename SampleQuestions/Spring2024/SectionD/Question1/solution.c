#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 7

int kClosePerm(int *perm, int *used, int n, int maxgap, int k)
{
    if (k == n)
    {
        return 1; // if k reaches the length return 1
    }

    int i;
    int res = 0;
    for (i = 0; i < n; i++)
    {
        if (!used[i])
        {                                                           // if i was not used
            if (k == 0) {
                used[i] = 1;                                            // mark that it is used
                perm[k] = i;                                            // transfer i to the the perm array at kth position
                res += kClosePerm(perm, used, n, maxgap, k + 1); // increase k and grow further
                used[i] = 0;                                            // unmark i for next process.
            } else {
                if (abs(perm[k - 1] - i) <= maxgap) {
                    used[i] = 1;                                            // mark that it is used
                    perm[k] = i;                                            // transfer i to the the perm array at kth position
                    res += kClosePerm(perm, used, n, maxgap, k + 1); // increase k and grow further
                    used[i] = 0;                                            // unmark i for next process.
                }
            }
        }
    }

    return res;
}

int main(void)
{
    int perm[SIZE] = {0}; // to build and store the permutation
    int used[SIZE] = {0}; // tracking which index is used
    int maxgap = 3;

    printf("Total permutations with maxgap %d: %d", maxgap, kClosePerm(perm, used, SIZE, maxgap, 0));

    return 0;
}