#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct _BasicHashTable {
    int capacity;
    int elementSize;
    void** elements;
} BasicHashTable;

BasicHashTable* new_BasicHashTable (int capacity, int elementSize) {
    BasicHashTable* newTable = malloc(sizeof(BasicHashTable)) ;
    newTable->capacity = capacity;
    newTable->elementSize = elementSize;
    newTable->elements = malloc(elementSize*capacity);
}

int BasicHashTable_Hash (BasicHashTable* table, const char* key) {
    int keySize = strlen(key);

    return (key[0] + key[1] + key[2] + key[keySize-2] + key[keySize-1])*252 % table->capacity;
}

void BasicHashTable_Insert (BasicHashTable* table, const char* key, void* obj) {
    if (key == 0 || obj == NULL) {
        return;
    }
    int hashResult = BasicHashTable_Hash(table, key);
    memcpy((table->elements + hashResult), obj, table->elementSize);
    printf("\nThe hash key is: %d", hashResult);
}

void* BasicHashTable_Retrieve (BasicHashTable* table, const char* key) {
    int hashResult = BasicHashTable_Hash(table, key);
    printf("\nThe hash key is: %d", hashResult);
    return (table->elements + hashResult);
}

int main (int input) {
    BasicHashTable* intTable = new_BasicHashTable(500, sizeof(int));
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

    int* result = (int*)BasicHashTable_Retrieve(intTable, "sixteen");
    printf("\nthe value retrieved is: %d", *result);
    result = (int*)BasicHashTable_Retrieve(intTable, "thirteen");
    printf("\nthe value retrieved is: %d", *result);
    result = (int*)BasicHashTable_Retrieve(intTable, "twelve");
    printf("\nthe value retrieved is: %d", *result);
}