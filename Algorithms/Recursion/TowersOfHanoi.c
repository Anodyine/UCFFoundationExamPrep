#include <stdio.h>
#include <stdlib.h>

#include "../../DataStructures/Stacks/ArrayStack.h"

#define NUM_DISKS 5

void checkAndMove(struct ArrayStack* sourceTower, struct ArrayStack* destTower) {
    if (ArrayStack_IsEmpty(sourceTower)){
        return;
    }

    if (ArrayStack_IsEmpty(destTower)) {
        ArrayStack_Push(destTower, ArrayStack_Pop(sourceTower));
        return;
    } 
    
    if (ArrayStack_Peek(sourceTower) < ArrayStack_Peek(destTower)) {
        ArrayStack_Push(destTower, ArrayStack_Pop(sourceTower));
    } else {
        printf("Cannot move larger disk on top of smaller one.\n");
    }
}

void printMoveAttempt (struct ArrayStack* sourceTower, struct ArrayStack* destTower) {
    if (ArrayStack_IsEmpty(destTower)) {
        printf ("Attempting to move %d onto an empty tower\n", ArrayStack_Peek(sourceTower));
    } else {
        printf ("Attempting to move %d on top of %d\n", ArrayStack_Peek(sourceTower), ArrayStack_Peek(destTower));
    }
}

void transferDisks(int numDisks, struct ArrayStack* sourceTower, struct ArrayStack* destTower, struct ArrayStack* auxTower) {
    if (numDisks == 1) { // this is the case when we're moving the last disk onto an almost completed tower
        printMoveAttempt(sourceTower, destTower);
        checkAndMove(sourceTower, destTower);
        return;
    }

    transferDisks(numDisks - 1, sourceTower, auxTower, destTower); // transfer all but the largest one from source to aux using dest
    printMoveAttempt(sourceTower, destTower);     
    checkAndMove(sourceTower, destTower); // transfer the largest disk from source to dest
    transferDisks(numDisks - 1, auxTower, destTower, sourceTower); // transfer the remaining disks from aux to dest using source
}

void printTower (struct ArrayStack* tower, int size, int towerNumber) {
    printf("Tower %d Contains:\n", towerNumber);
    for (int i = size-1; i >= 0; i--) {
        printf("%d\n", tower->data[i]);
    }
}

int main (int) {
    struct ArrayStack tower1;
    ArrayStack_init(&tower1);
    struct ArrayStack tower2;
    ArrayStack_init(&tower2);
    struct ArrayStack tower3;
    ArrayStack_init(&tower3);

    for (int i = NUM_DISKS; i > 0; i--) {
        ArrayStack_Push(&tower1, i);
    }

    printTower(&tower1, NUM_DISKS, 1);

    transferDisks(NUM_DISKS, &tower1, &tower3, &tower2);

    printTower(&tower3, NUM_DISKS, 3);
}