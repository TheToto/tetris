#pragma once

#include "tetris.h"

struct game *game_init(void);
void game_destroy(struct game *game);

int update(struct game *game, int *score);
