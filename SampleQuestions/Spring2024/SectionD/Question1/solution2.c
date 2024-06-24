#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int kClosePerm(int *perm, int *used, int n, int maxgap, int k)
{
    if (n == k)
        return 1; // 1 pt
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue; // 1 pt
        if (k > 0 && abs(perm[k - 1] - i) > maxgap)
            continue;                                    // 2 pts
        used[i] = 1;                                     // 1 pt
        perm[k] = i;                                     // 1 pt
        res += kClosePerm(perm, used, n, maxgap, k + 1); // 3 pts
        used[i] = 0;                                     // 1 pt
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