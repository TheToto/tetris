#pragma once

#include "tetris.h"

int random_bloc_type(void);

struct bloc *bloc_init(int type);
void bloc_destroy(struct bloc *bloc);
