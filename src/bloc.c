#include "bloc.h"



int random_bloc_type(void)
{
    int r = random() % 7;
    switch (r)
    {
    case 0:
        return BLOC_O;
        break;
    case 1:
        return BLOC_I;
        break;
    case 2:
        return BLOC_L;
        break;
    case 3:
        return BLOC_T;
        break;
    case 4:
        return BLOC_J;
        break;
    case 5:
        return BLOC_S;
        break;
    case 6:
        return BLOC_Z;
        break;
    }
    return 0;
}



struct bloc *bloc_init(int type)
{
    struct bloc *res = malloc(sizeof(struct bloc));
    res->pos_x = INIT_X;
    res->pos_y = INIT_Y;
    res->type = type;
    res->rot = 0;
    res->c = type;

    res->diff_x = points_bloc_x(type, res->rot);
    res->diff_y = points_bloc_y(type, res->rot);

    return res;
}


int bloc_move(struct game *game, int left)
{
    struct bloc *bloc = game->cur_bloc;
    if (left)
        bloc->pos_x--;
    else
        bloc->pos_x++;
    if (is_coliding(game->map, bloc))
    {
        if (left)
            bloc->pos_x++;
        else
            bloc->pos_x--;
        return 1;
    }

    return 0;
}

int bloc_down(struct game *game, int bottom)
{
    struct bloc *bloc = game->cur_bloc;
    bloc->pos_y++;

    if (is_coliding(game->map, bloc))
    {
        bloc->pos_y--;
        return 0;
    }
    while (bottom && !is_coliding(game->map, bloc))
        bloc->pos_y++;

    if (bottom)
        bloc->pos_y--;
    return 2 + bottom;
}

int bloc_rotate(struct game *game)
{
    if (game->cur_bloc->type == BLOC_O)
        return 1;
    struct bloc *bloc = game->cur_bloc;

    bloc->rot = (bloc->rot + 1) % 4;

    free(bloc->diff_x);
    free(bloc->diff_y);

    bloc->diff_x = points_bloc_x(bloc->type, bloc->rot);
    bloc->diff_y = points_bloc_y(bloc->type, bloc->rot);


//    if (bloc TODO bloc S and Z mirrored


    if (is_coliding(game->map, bloc))
    {
        bloc->rot = (bloc->rot - 1) % 4;
        free(bloc->diff_x);
        free(bloc->diff_y);

        bloc->diff_x = points_bloc_x(bloc->type, bloc->rot);
        bloc->diff_y = points_bloc_y(bloc->type, bloc->rot);
        return 1;
    }
    return 0;
}

void bloc_destroy(struct bloc *bloc)
{
    free(bloc->diff_x);
    free(bloc->diff_y);
    free(bloc);
}


int *points_bloc_x(int type, int rot)
{
    if (rot == 1 || rot == 3)
        return points_bloc_y(type, rot - 1);

    int *res = calloc(sizeof(int), 4);
    switch(type)
    {
    case BLOC_O:
        res[1] = 1;
        res[3] = 1;
        break;
    case BLOC_I:
        break;
    case BLOC_L:
        res[3] = 1;
        break;
    case BLOC_T:
        res[1] = -1;
        res[3] = 1;
        break;
    case BLOC_J:
        res[2] = -1;
        break;
    case BLOC_S:
        res[1] = 1;
        res[2] = -1;
        break;
    case BLOC_Z:
        res[0] = -1;
        res[3] = 1;
        break;
    }

    if (rot == 2)
    {
        for (int i = 0; i < 4; i++)
            res[i] = -res[i];
    }

    return res;
}

int *points_bloc_y(int type, int rot)
{
    if (rot == 1 || rot == 3)
        return points_bloc_x(type, rot - 1);

    int *res = calloc(sizeof(int), 4);

    switch(type)
    {
    case BLOC_O:
        res[0] = -1;
        res[1] = -1;
        break;
    case BLOC_I:
        res[0] = -2;
        res[1] = -1;
        res[3] = 1;
        break;
    case BLOC_L:
        res[0] = -1;
        res[2] = 1;
        res[3] = 1;
        break;
    case BLOC_T:
        res[0] = -1;
        break;
    case BLOC_J:
        res[0] = -1;
        res[2] = 1;
        res[3] = 1;
        break;
    case BLOC_S:
        res[0] = -1;
        res[1] = -1;
        break;
    case BLOC_Z:
        res[0] = -1;
        res[1] = -1;
        break;
    }

    if (rot == 2)
    {
        for (int i = 0; i < 4; i++)
            res[i] = -res[i];
    }

    return res;
}
