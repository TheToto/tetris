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
    if (!c)
        printf(" ");
    else
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


int is_coliding(char **map, struct bloc *bloc)
{
    int x = bloc->pos_x;
    int y = bloc->pos_y;
    int *diff_x = bloc->diff_x;
    int *diff_y = bloc->diff_y;

    for (int i = 0; i < 4; i++)
    {
        if (x + diff_x[i] >= WIDTH || x + diff_x[i] < 0
            || y + diff_y[i] >= HEIGHT || y + diff_y[i] < 0)
            return 2;

        if (map[y + diff_y[i]][x + diff_x[i]] == '#')
            return 1;
    }
    return 0;
}
int put_bloc(char **map, struct bloc *bloc)
{
    if (is_coliding(map, bloc))
        return 1;

    int x = bloc->pos_x;
    int y = bloc->pos_y;
    int *diff_x = bloc->diff_x;
    int *diff_y = bloc->diff_y;

    for (int i = 0; i < 4; i++)
        map[y + diff_y[i]][x + diff_x[i]] = '#';
    return 0;
}


void print_map(char **map, struct bloc *bloc)
{
    for (int i = 0; i < WIDTH + 2; i++)
        printf("-");
    printf("\n");

    int x = bloc->pos_x;
    int y = bloc->pos_y;
    int *diff_x = bloc->diff_x;
    int *diff_y = bloc->diff_y;


    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            for (int n = 0; n < 4; n++)
            {
                if (j == x + diff_x[n] && i == y + diff_y[n])
                {
                    print_char(bloc->c);
                    break;
                }
                if (n == 3)
                    print_char(map[i][j]);
            }
        }
        printf("|\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("-");
    printf("\n");
}
