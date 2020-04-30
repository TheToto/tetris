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
    if (c == 0)
    {
        printf("  ");
        return;
    }

    switch(c)
    {
    case BLOC_O:
        printf(YEL);
        break;
    case BLOC_I:
        printf(CYN);
        break;
    case BLOC_L:
        printf(WHT);
        break;
    case BLOC_T:
        printf(MAG);
        break;
    case BLOC_J:
        printf(BLU);
        break;
    case BLOC_S:
        printf(GRN);
        break;
    case BLOC_Z:
        printf(RED);
        break;
    }
    printf("██" RESET);
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

        if (map[y + diff_y[i]][x + diff_x[i]] != 0)
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
        map[y + diff_y[i]][x + diff_x[i]] = bloc->type;
    return 0;
}

static void remove_line(char **map, int n)
{
    int i = n;
    while (i > 0)
    {
        for (int j = 0; j < WIDTH; j++)
            map[i][j] = map[i - 1][j];
        i--;
    }
    for (int j = 0; j < WIDTH; j++)
        map[0][j] = 0;
}

int check_lines(char **map)
{
    int ret = 0;
    for (int i = 0; i < HEIGHT; i++)
    {
        int j = 0;
        while (j < WIDTH && map[i][j] != 0)
            j++;
        if (j >= WIDTH)
        {
            remove_line(map, i);
            ret = 1;
        }
    }

    return ret;
}


void print_map(char **map, struct bloc *bloc, int score)
{
    printf(CLEAR); // A lot faster than system("clear")
    printf("╔");
    for (int i = 1; i < WIDTH + 1; i++)
        printf("══");
    printf("╗");
    printf("\r\n");

    int x = bloc->pos_x;
    int y = bloc->pos_y;
    int *diff_x = bloc->diff_x;
    int *diff_y = bloc->diff_y;


    for (int i = 0; i < HEIGHT; i++) {
        printf("║");
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
        printf("║\r\n");
    }
    printf("╚");
    for (int i = 1; i < WIDTH + 1; i++)
        printf("══");
    printf("╝");
    printf("\r\n");
    printf("Score : %d", score);
}
