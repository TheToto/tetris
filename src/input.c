#include "input.h"


int get_input(struct game *game, int value)
{
    if (value != ' ' && value != 'z' && value != 'q' && value != 's' && value != 'd')
        return 0;

    if (value == 'z')
        return !bloc_rotate(game);
    if (value == 's' || value == ' ')
        return bloc_down(game, value == ' ');
    return !bloc_move(game, value == 'q');
}
