#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Monster {
// Details not necessary to solve the problem.
    char name[32]; //Added this for demonstration purposes
} Monster;

typedef struct Monster_List {
    Monster** mArray;
    int numMonsters;
} Monster_List;

// Initializes the monster pointed to by mPtr to be the default
// monster.
void initializeMonster(Monster* mPtr);

Monster_List* getDefaultMonsters(int n) {
    Monster** monsters = (Monster**)malloc(sizeof(Monster*)*n);

    for (int i = 0; i < n; i++) {
        monsters[i] = (Monster*)malloc(sizeof(Monster));
        initializeMonster(monsters[i]);
    }

    Monster_List* result = (Monster_List*)malloc(sizeof(Monster_List));
    result->mArray = monsters;
    result->numMonsters = n;

    return result;
}

void initializeMonster (Monster* mPtr) {
    strcpy(mPtr->name, "Omen Killer");
}

int main (int) {
    Monster_List* myMonsters = getDefaultMonsters(10);

    for (int i = 0; i < 10; i++) {
        printf("%s\n", myMonsters->mArray[i]->name);
    }

    for (int i = 0; i < 10; i++) {
        free(myMonsters->mArray[i]);
    }
}