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
    res->c = '#';

    res->diff_x = points_bloc_x(type, res->rot);
    res->diff_y = points_bloc_y(type, res->rot);

    return res;
}


void bloc_destroy(struct bloc *bloc)
{
    free(bloc->diff_x);
    free(bloc->diff_y);
    free(bloc);
}


int *points_bloc_x(int type, int rot)
{
    rot = rot;
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
    return res;
}

int *points_bloc_y(int type, int rot)
{
    rot = rot;
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
    return res;
}
