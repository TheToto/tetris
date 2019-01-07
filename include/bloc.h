#pragma once

#include "tetris.h"

int random_bloc_type(void);

struct bloc *bloc_init(int type);
void bloc_destroy(struct bloc *bloc);

int *points_bloc_x(int type, int rot);
int *points_bloc_y(int type, int rot);

int bloc_move(struct game *game, int left);
int bloc_rotate(struct game *game);
/*

##
O#

#
#
O
#

#
0
##

 #
#0#

 #
 0
##

 ##
#0

##
 0#

 */
