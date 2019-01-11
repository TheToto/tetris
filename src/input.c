#include "input.h"


int get_input(struct game *game, int value, short *pressed)
{
    if (value != 57 && value != 200 && value != 203 && value != 205 && value != 208)
        return 0;

    if (*pressed)
    {
        *pressed = 0;
        return 0;
    }

    *pressed = 1;
    if (value == 200)
        return !bloc_rotate(game);
    if (value == 208 || value == 57)
        return bloc_down(game, value == 57);
    return !bloc_move(game, value == 203);
}
