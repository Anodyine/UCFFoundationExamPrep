#include <stdio.h>

int max (int a, int b) {
    return (a > b) ? a: b;
}

int getKnapSackMaxValue (int capacity, int itemWeights[], int itemValues[], int numberOfItems) {
    if (numberOfItems == 0 || capacity == 0)
        return 0;

    if (itemWeights[numberOfItems - 1] > capacity) { // if the last item exceeds the remaining capacity
        return getKnapSackMaxValue(capacity, itemWeights, itemValues, numberOfItems - 1);
    } else {
        return max( // compare adding this item to the sack to comparing the best combination of all of the remaining items
            itemValues[numberOfItems - 1] + getKnapSackMaxValue(capacity - itemWeights[numberOfItems - 1], itemWeights, itemValues, numberOfItems - 1),
            getKnapSackMaxValue(capacity, itemWeights, itemValues, numberOfItems -1)
        );
    }

}

int main () {
    int itemValues[] = {60, 100, 120};
    int itemWeights[] = {10, 20, 30};
    int capacity = 50;
    int numberOfItems = 3;
    printf("%d", getKnapSackMaxValue(capacity, itemWeights, itemValues, numberOfItems));
    return 0;
}