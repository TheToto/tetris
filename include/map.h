#pragma once

#include "tetris.h"


char **map_init(void);
void map_destroy(char **map);

void print_map(char **map, struct bloc *bloc);

int check_lines(char **map);
int is_coliding(char **map, struct bloc *bloc);
int put_bloc(char **map, struct bloc *bloc);


