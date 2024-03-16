#include <string.h>
#include <stdlib.h>
#include "Point.c";

// making the exteral "interface" "public"
typedef struct _ThoughtPoint ThoughtPoint;

// We don't want them to use this one
typedef struct _ThoughtPoint {
    Point *point;
    char **thought;
} ThoughtPoint;

typedef struct {
    char *letters;
    int length;
} Word;

ThoughtPoint* new_ThoughtPoint (int x, int y, char* label, Word* words, int numberOfWords) {
    ThoughtPoint *thoughtPointPtr;
    Point *pointPtr;

    pointPtr->x = x;
    pointPtr->y = y;
    strcpy(pointPtr->label, label);

    thoughtPointPtr->point = pointPtr;

    for (int i = 0; i < numberOfWords; i++) {
        
    }
    return thoughtPointPtr;
}

void delete_ThoughtPoint(ThoughtPoint* thoughtPointPtr) {
    free(thoughtPointPtr->thought);
    return;
}
