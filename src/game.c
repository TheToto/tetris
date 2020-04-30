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


int update(struct game *game, int *score)
{
    game->cur_bloc->pos_y++;
    if (is_coliding(game->map, game->cur_bloc))
    {
        game->cur_bloc->pos_y--;

        put_bloc(game->map, game->cur_bloc);
        bloc_destroy(game->cur_bloc);
        game->cur_bloc = bloc_init(game->next);
        game->next = random_bloc_type();
        if (is_coliding(game->map, game->cur_bloc) == 1)
            return 1;
        *score += check_lines(game->map);
    }
    return 0;
}
