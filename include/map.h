#pragma once

#include "tetris.h"

char **map_init(void);
void map_destroy(char **map);

void print_map(char **map);
