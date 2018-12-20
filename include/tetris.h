#pragma once

#define _XOPEN_SOURCE 500

#define WIDTH 10
#define HEIGHT 20
#define INIT_X 5
#define INIT_Y 1

#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "game.h"
#include "bloc.h"

enum bloc_type {
    BLOC_O,
    BLOC_I,
    BLOC_L,
    BLOC_T,
    BLOC_J,
    BLOC_S,
    BLOC_Z
};

struct bloc {

    int pos_x;
    int pos_y;
    enum bloc_type type;
    short rot;
};

struct game {
    enum bloc_type next;
    struct bloc *cur_bloc;
    char **map;
};
