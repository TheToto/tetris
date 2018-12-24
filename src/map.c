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

static int *points_bloc_x(int type)
{
    int *res = calloc(sizeof(int), 4);
}


static int *point_bloc_y(int type)
{
    int *res = calloc(sizeof(int), 4);


    return res;
}

int put_bloc(char **map, struct bloc)
{
    int x = bloc->pos_x;
    int y = bloc->pos_y;
    int *x_diff = points_bloc_x(bloc->type); // 4 blocks
    int *y_diff = points_bloc_y(bloc->type); // 4 blocks
    for (int i = 0; i < 4; i++)
    { 
        if (map[x + x_diff[i]][y + y_diff[i]] == '#')
        {
            free(x_diff);
            free(y_diff);
            return 1;
        }
    }
    for (int i = 0; i < 4; i++)
        map[x + x_diff[i]][y + y_diff[i]] = '#';
    free(x_diff);
    free(y_diff);
    return 0;
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
