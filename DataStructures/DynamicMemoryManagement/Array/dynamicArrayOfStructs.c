#include <stdio.h>
#include <stdlib.h>
#include "../../../Shared/Point.h"

int main() {
    Point myPoint1 = {
        label: "hi",
        x: 10,
        y: 20
    };

    Point myPoint2 = {
        label: "hi2",
        x: 20,
        y: 40
    };

    Point *myPoints = (Point*)malloc(sizeof(Point) * 10);

    if (myPoints == NULL) {
        printf("Failed to allocate memory for myPoints...\n");
        return 1;
    }

    myPoints[0] = myPoint1;
    myPoints[1] = myPoint2;
    myPoints[10] = myPoint2;

    printf("\n Point 1 is: %s at (%d, %d)", myPoints[0].label, myPoints[0].x, myPoints[0].y);
    printf("\n Point 2 is: %s at (%d, %d)", myPoints[1].label, myPoints[1].x, myPoints[1].y);
    printf("\n Point 3 is : %s at (%d, %d)", myPoints[10].label, myPoints[10].x, myPoints[10].y);

    free(myPoints);
    return 0;
}