#pragma once

#define _XOPEN_SOURCE 500

#define _DEFAULT_SOURCE

#define WIDTH 10
#define HEIGHT 20
#define INIT_X 5
#define INIT_Y 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include <string.h>
#include <sys/select.h>
#include <termios.h>

#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>

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
    char c;

    int *diff_x;
    int *diff_y;
    short rot;
};


struct game {
    enum bloc_type next;
    struct bloc *cur_bloc;
    char **map;
};


#include "map.h"
#include "game.h"
#include "bloc.h"
#include "input.h"
