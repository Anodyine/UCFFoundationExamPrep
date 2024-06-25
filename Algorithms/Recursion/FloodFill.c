#include <stdio.h>
#include <stdlib.h>

void fill(char** map, int numRows, int x, int y)
{
    if (x <= 0 || map[y][x] == '\0' || y > numRows || y < 0)
    {
        return;
    }

    if (map[y][x] == ' ')
    {
        map[y][x] = '~';
    }

    if (map[y + 1][x] == ' ')
    {
        fill(map, numRows, x, y + 1);
    }

    if (map[y - 1][x] == ' ')
    {
        fill(map, numRows, x, y - 1);
    }

    if (map[y][x + 1] == ' ')
    {
        fill(map, numRows, x + 1, y);
    }

    if (map[y][x - 1] == ' ')
    {
        fill(map, numRows, x - 1, y);
    }
}

void printMap(char **map, int numRows)
{
    for (int i = 0; i < numRows; i++)
    {
        printf("%s\n", map[i]);
    }
}

int main(int)
{
    char **map = malloc(sizeof(char *) * 10);
    char data[110] = {
        '*','*','*','*','*','*','*','*','*','*','\0',
        '*','*',' ',' ','*','*','*',' ',' ','*','\0',
        '*',' ',' ',' ','*','*',' ',' ',' ','*','\0',
        '*',' ',' ',' ',' ','*','*','*','*','*','\0',
        '*',' ',' ',' ',' ',' ',' ','*','*','*','\0',
        '*',' ',' ','*','*','*',' ',' ','*','*','\0',
        '*',' ',' ','*','*','*',' ',' ','*','*','\0',
        '*',' ',' ','*','*','*',' ',' ',' ','*','\0',
        '*',' ',' ','*','*','*','*','*','*','*','\0',
        '*','*','*','*','*','*','*','*','*','*','\0'
    };

    for(int i = 0; i < 10; i++) {
        map[i] = malloc(sizeof(char) * (10 + 1));
        for (int j = 0; j < 11; j++) {
            map[i][j] = data[11 * i + j];
        }
    }

    printf("Before filling:\n");
    printMap(map, 10);

    fill(map, 10, 7, 1);

    printf("After filling:\n");
    printMap(map, 10);
}
