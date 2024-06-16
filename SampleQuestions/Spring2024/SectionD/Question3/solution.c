#include <stdio.h>

#include <math.h>
int leastBitsOn(int x) { 
    int numOn = 0; 
    int cur = 0; 
    int longest = 0; 

    // checking for powers of 2 first
    if ((ceil(log2(x)) == floor(log2(x)))) {
        return 1;
    }
 
    // iterate for each bit in the integer
    for (int i = 0; i < 8*sizeof(int); i++) {
        // if we find an on bit
        // Bitwise left shift works like this: 0000000001 << 8 = 0100000000
        // Bitwise and works like this: 0100000000 & 0101010010 = 0100000000 // 0000000001 & 0101010010 = 0000000000
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