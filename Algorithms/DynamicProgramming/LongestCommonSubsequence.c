#include <stdio.h>
#include <string.h>

int lcsLength (char* string1, char* string2, int length1, int length2) {
    int sequenceLengths[length1+1][length2+1];

    for (int i = 0; i <= length1; i++) {
        for (int j = 0; j <= length2; j++) {
            if (i == 0 || j == 0) {
                sequenceLengths[i][j] = 0;
            } else if (string1[i-1] == string2[j-1]) {
                sequenceLengths[i][j] = sequenceLengths[i-1][j-1] + 1;
            } else {
                sequenceLengths[i][j] = (sequenceLengths[i-1][j] > sequenceLengths[i][j-1]) ? sequenceLengths[i-1][j] : sequenceLengths[i][j-1];
            }
        }
    }

    int result = sequenceLengths[length1][length2];
    int length = result;
    char matchingString[length];
    matchingString[length] = '\0';

    int i = length1;
    int j = length2;
    // finding the letters that were matched in the substring.
    while (i > 0 && j > 0) {
        if (string1[i-1] == string2[j-1]) {
            matchingString[length-1] = string1[i-1];
            i--;
            j--;
            length--;
        } else if (sequenceLengths[i-1][j] > sequenceLengths[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("The longest matching subsequence is: %s.\n", matchingString);

    return result;
}

int main(int input) {
    char string1[] = "AGGTAB";
    char string2[] = "GXTXAYB";
    int m = strlen(string1);
    int n = strlen(string2);

    printf("Length of the LCS is %d.\n", lcsLength(string1, string2, m, n));

    return 0;
}