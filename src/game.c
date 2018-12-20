#include "game.h"


struct game *game_init(void)
{
    struct game *res = malloc(sizeof(struct game));

    res->next = random_bloc_type();
    res->cur_bloc = bloc_init(random_bloc_type());
    res->map = map_init();
    return res;
}


void game_destroy(struct game *game)
{
    map_destroy(game->map);
    bloc_destroy(game->cur_bloc);
    free(game);
}
