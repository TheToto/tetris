#pragma once

#include <stdio.h>
#include <stdlib.h>


char **map_init(void);
void map_destroy(char **map);

void print_map(char **map);
