#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct _BasicHashTable {
    int capacity;
    int elementSize;
    void* emptyValue;
    void** elements;
} BasicHashTable;

BasicHashTable* new_BasicHashTable (int capacity, int elementSize, void* emptyValue) {
    BasicHashTable* newTable = malloc(sizeof(BasicHashTable)) ;
    newTable->capacity = capacity;
    newTable->emptyValue = emptyValue;
    newTable->elementSize = elementSize;
    newTable->elements = malloc(capacity*sizeof(void*)); // we need these to be set to 0 so we can check if they are empty later

    for (int i = 0; i < capacity; i++)
        *(newTable->elements + i) = calloc(capacity, elementSize); // we need these to be set to 0 so we can check if they are empty later

    return newTable;
}

int BasicHashTable_Hash (BasicHashTable* table, const char* key) {
    int keySize = strlen(key);
    int hashedKey = 0;

    for (int i = 0; i < keySize; i++) {
        hashedKey += key[i];
    }

    return hashedKey*252 % table->capacity;
}

void BasicHashTable_Insert (BasicHashTable* table, const char* key, void* obj) {
    if (key == 0 || obj == NULL) {
        return;
    }
    int hashResult = BasicHashTable_Hash(table, key);
    memcpy(*(table->elements + hashResult), obj, table->elementSize);
    printf("\nThe hashedKey is: %d", hashResult);
}

void* BasicHashTable_Retrieve (BasicHashTable* table, const char* key, int (*compareFunction)(void*,void*)) {
    int hashResult = BasicHashTable_Hash(table, key);
    printf("\nThe hashedKey is: %d", hashResult);
    while (compareFunction(*(table->elements + hashResult), table->emptyValue) == 0) {
        hashResult = (hashResult + 1)%table->capacity;
    }
    return *(table->elements + hashResult);
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
    BasicHashTable* intTable = new_BasicHashTable(500, sizeof(int), &zero);
    int value = 16;
    char key[500];
    strcpy(key,"sixteen");
    printf("\nthe value inserted is: %d", value);
    BasicHashTable_Insert(intTable, key, &value);
    value = 12;
    strcpy(key,"twelve");
    BasicHashTable_Insert(intTable, key, &value);
    value = 13;
    strcpy(key,"thirteen");
    BasicHashTable_Insert(intTable, key, &value);

    int* result = (int*)BasicHashTable_Retrieve(intTable, "sixteen", compareFunctionPointer);
    printf("\nthe value retrieved is: %d", *result);
    result = (int*)BasicHashTable_Retrieve(intTable, "thirteen", compareFunctionPointer);
    printf("\nthe value retrieved is: %d", *result);
    result = (int*)BasicHashTable_Retrieve(intTable, "twelve", compareFunctionPointer);
    printf("\nthe value retrieved is: %d", *result);
    result = (int*)BasicHashTable_Retrieve(intTable, "fifteen", compareFunctionPointer);
    printf("\nthe value retrieved is: %d", *result);
}