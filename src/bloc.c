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
    return res;
}


void bloc_destroy(struct bloc *bloc)
{
    free(bloc);
}
