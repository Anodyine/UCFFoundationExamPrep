#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct _TableEntry {
    char key[500];
    void* data;
} TableEntry;

typedef struct _BasicHashTable {
    int capacity;
    int elementSize;
    TableEntry** elements;
} BasicHashTable;

BasicHashTable* new_BasicHashTable (int capacity, int elementSize) {
    BasicHashTable* newTable = malloc(sizeof(BasicHashTable)) ;
    newTable->capacity = capacity;
    newTable->elementSize = elementSize;
    newTable->elements = malloc(capacity*sizeof(TableEntry*));

    for (int i = 0; i < capacity; i++){
        *(newTable->elements + i) = malloc(sizeof(TableEntry));
        strcpy((*(newTable->elements + i))->key, "\0");
        (*(newTable->elements + i))->data = NULL;
    }

    return newTable;
}

int BasicHashTable_Hash (BasicHashTable* table, const char* key) {
    int keySize = strlen(key);
    int hashedKey = 0;

    hashedKey = key[0] + key[1] + key[keySize - 1] + key[keySize - 2];
    // for (int i = 0; i < keySize; i++) {
    //     hashedKey += key[i];
    // }

    return hashedKey*252 % table->capacity;
}

void BasicHashTable_Insert (BasicHashTable* table, const char* key, void* obj) {
    if (key == 0 || obj == NULL) {
        return;
    }
    int hashResult = BasicHashTable_Hash(table, key);
    while ((*(table->elements + hashResult))->data != NULL) { //while we haven't found an empty space
        printf("\n linear probe required for insert");
        hashResult = (hashResult + 1) % table->capacity;
    }

    strcpy((*(table->elements + hashResult))->key, key);
    (*(table->elements + hashResult))->data = malloc(sizeof(table->elementSize));
    memcpy((*(table->elements + hashResult))->data, obj, table->elementSize);
}

void* BasicHashTable_Retrieve (BasicHashTable* table, const char* key) {
    int hashResult = BasicHashTable_Hash(table, key);

    if ((*(table->elements + hashResult))->data == NULL) {
        return NULL;
    }

    while (key[0] != (*(table->elements + hashResult))->key[0] 
        || !strcmp(key, (*(table->elements + hashResult))->key) == 0) { // while we haven't found the matching key
        hashResult = (hashResult + 1)%table->capacity;
        printf("\n linear probe required for retrieve");
        if ((*(table->elements + hashResult))->data == NULL) {
            return NULL;
        }
    }

    return (*(table->elements + hashResult))->data;
}

int compareInts (void* a, void* b) { 
    int value1 = *((int*)a);
    int value2 = *((int*)b);

    if (value1 > value2) {
        return 1;
    }

    if (value1 < value2) {
        return -1;
    }

    return 0;
}

int main (int input) {
    int (*compareFunctionPointer)(void*,void*) = &compareInts;
    int zero = 0;
    BasicHashTable* intTable = new_BasicHashTable(500, sizeof(int));
    int value = 16;
    char key[500];
    strcpy(key,"sixteen");
    BasicHashTable_Insert(intTable, key, &value);
    value = 12;
    strcpy(key,"twelve");
    BasicHashTable_Insert(intTable, key, &value);
    value = 13;
    strcpy(key,"thirteen");
    BasicHashTable_Insert(intTable, key, &value);


    int* result = (int*)BasicHashTable_Retrieve(intTable, "sixteen");
    printf("\nthe value retrieved is: %d", *result);
    result = (int*)BasicHashTable_Retrieve(intTable, "thirteen");
    printf("\nthe value retrieved is: %d", *result);
    result = (int*)BasicHashTable_Retrieve(intTable, "twelve");
    printf("\nthe value retrieved is: %d", *result);
    result = (int*)BasicHashTable_Retrieve(intTable, "fifteen");
    if (result == NULL) {
        printf("\nthe value was not found");
    } else {
        printf("\nthe value retrieved is: %d", *result);
    }
}