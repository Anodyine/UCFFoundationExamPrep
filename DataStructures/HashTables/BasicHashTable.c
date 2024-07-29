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
    int maxEntries;
    int dataTypeSize;
    TableEntry** entries;
} BasicHashTable;

BasicHashTable* new_BasicHashTable (int maxEntries, int dataTypeSize) {
    BasicHashTable* newTable = malloc(sizeof(BasicHashTable)) ;
    newTable->maxEntries = maxEntries;
    newTable->dataTypeSize = dataTypeSize;
    newTable->entries = malloc(maxEntries*sizeof(TableEntry*));

    for (int i = 0; i < maxEntries; i++){
        newTable->entries[i] = malloc(sizeof(TableEntry));
        strcpy(newTable->entries[i]->key, "\0");
        newTable->entries[i]->data = NULL;
    }

    return newTable;
}

int BasicHashTable_CreateIndexFromKey (BasicHashTable* table, const char* key) {
    int keySize = strlen(key);
    int hashedKey = 0;

    hashedKey = key[0] + key[1] + key[keySize - 1] + key[keySize - 2]; // hash function intentionally chosen to create a collision
    // for (int i = 0; i < keySize; i++) {
    //     hashedKey += key[i];
    // }

    return hashedKey*251 % table->maxEntries;
}

int BasicHashTable_LinearProbe(BasicHashTable* table, int createdIndex) {
    return (createdIndex + 1)%table->maxEntries;
}

void BasicHashTable_Insert (BasicHashTable* table, char* key, void* obj) {
    if (key == 0 || obj == NULL) {
        return;
    }
    int createdIndex = BasicHashTable_CreateIndexFromKey(table, key);
    while (table->entries[createdIndex]->data != NULL) { //while we haven't found an empty space
        printf("\n linear probe required for insert");
        createdIndex = BasicHashTable_LinearProbe(table, createdIndex);
    }

    strcpy(table->entries[createdIndex]->key, key);
    table->entries[createdIndex]->data = malloc(sizeof(table->dataTypeSize));
    memcpy(table->entries[createdIndex]->data, obj, table->dataTypeSize);
}

bool stringsAreEqual(char* str1, char* str2)
{
    int i = 0;

    while(str1[i]==str2[i])
    {
        if(str1[i]=='\0'||str2[i]=='\0')
            break;
        i++;
    }
    if(str1[i]=='\0' && str2[i]=='\0')
        return true;
    else
        return false;
}

void* BasicHashTable_Retrieve (BasicHashTable* table, char* key) {
    int createdIndex = BasicHashTable_CreateIndexFromKey(table, key);

    if (table->entries[createdIndex]->data == NULL) {
        return NULL;
    }

    while (!stringsAreEqual(key, table->entries[createdIndex]->key)) { // while we haven't found the matching key
        createdIndex = BasicHashTable_LinearProbe(table, createdIndex);
        printf("\n linear probe required for retrieve");
        if (table->entries[createdIndex]->data == NULL) {
            return NULL;
        }
    }

    return table->entries[createdIndex]->data;
}

int main (int input) {
    int zero = 0;
    BasicHashTable* intTable = new_BasicHashTable(500, sizeof(int));
    int value = 16;
    char key[500];
    strcpy(key,"sixteen");
    BasicHashTable_Insert(intTable, key, &value);
    printf("\n{%s}: %d was inserted", key, value);

    value = 12;
    strcpy(key,"twelve");
    BasicHashTable_Insert(intTable, key, &value);
    printf("\n{%s}: %d was inserted", key, value);
    
    value = 13;
    strcpy(key,"thirteen");
    BasicHashTable_Insert(intTable, key, &value);
    printf("\n{%s}: %d was inserted", key, value);


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