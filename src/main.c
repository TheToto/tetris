#include "tetris.h"



int main()
{
    srandom(4);
    struct game *game = game_init();
    game_destroy(game);
    return 0;
}
