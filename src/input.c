#include "input.h"


int get_input(struct game *game, int value)
{
    if (value != ' ' && value != 'z' && value != 'q' && value != 's' && value != 'd')
        return 0;

    if (value == 'z')
        return !bloc_rotate(game); // true (1) if redraw
    if (value == 's' || value == ' ')
        return bloc_down(game, value == ' '); // 3 if next bloc, else 2.
    return !bloc_move(game, value == 'q'); // true (1) if redraw
}
