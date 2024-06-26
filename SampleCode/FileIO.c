#include <stdio.h>
#include <unistd.h>

int main (int) {
    const char *fileName = "testFile.txt";
    FILE *filePtr;
    if (access(fileName, F_OK) == 0) {
        // file exists
        filePtr = fopen("testFile.txt", "r+");
    } else {
        // file doesn't exist
        filePtr = fopen("testFile.txt", "w+");
    }

    fprintf(filePtr, "Hello File!");

    fclose(filePtr);

    filePtr = fopen("testFile.txt", "r+");
    char currentChar;
    char fileReadResult[100];
    int i = 0;
    do {
        currentChar = fgetc(filePtr);
        fileReadResult[i] = currentChar;
        i++;
    } while (currentChar != EOF);

    fileReadResult[i] = '\0';
    printf("%s", fileReadResult);
}