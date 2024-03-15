#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char label[20];
    int x;
    int y;
} Point;

int main() {
    Point *myPoint = malloc(sizeof(Point));
    printf("Please enter a name for your point:\n");
    scanf("%s", &(myPoint->label));
    printf("Please enter x coordinate:\n");
    scanf("%d", &(myPoint->x));
    printf("Please enter y coordinate:\n");
    scanf("%d", &(myPoint->y));

    printf("\n You entered: %s at (%d, %d)", myPoint->label, myPoint->x, myPoint->y);
    free(myPoint);

    return 0;
}