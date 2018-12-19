#include "tetris.h"
#include "map.h"

char **map_init(void)
{
    char **res = malloc(sizeof(char*) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++)
        res[i] = calloc(sizeof(char), WIDTH);
    return res;
}


void map_destroy(char **map)
{
    for (int i = 0; i < HEIGHT; i++)
        free(map[i]);
    free(map);
}




static void print_char(char c)
{
    printf("%c", c);
    /*
    switch(c)
    {
    case '#':
        printf("#");
        break;
    case ' ':
        printf(" ");
        break;
    }
    */
}

void print_map(char **map)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
            print_char(map[i][j]);
        printf("\n");
    }
    printf("\n");
}
