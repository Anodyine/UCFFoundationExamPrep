#include <stdio.h>

int leastBitsOn(int x) { 
    int numOn = 0; 
    int cur = 0; 
    int longest = 0; 
 
    // iterate for each bit in the integer
    for (int i = 0; i < 8*sizeof(int); i++) {
        // if we find an on bit
        if ((x&(1<<i)) != 0) {
            cur++;
            numOn++;
        } else {
            cur = 0;
        }

        if (cur > longest) {
            longest = cur;
        }
    }

    return numOn - longest + 1;
}

int main (int) {
    int userInput;
    int result;
    while(1==1) {
        printf("Please enter an integer:\n");
        scanf("%d", &userInput);

        result = leastBitsOn (userInput);

        printf("The result is: %d\n", result);
    }

    return 0;
}