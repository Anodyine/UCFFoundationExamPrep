#include <stdio.h>

struct Point {
    int x;
    int y;
};


int main (int) {
    struct Point point = {
        .x = 6,
        .y = 7
    };

    printf("x is: %d, y is %d\n", point.x, point.y);

    point.x = 18;
    point.y = 25;

    printf("x is: %d, y is %d\n", point.x, point.y);
}