#include "tetris.h"

struct termios orig_termios;

void reset_terminal_mode();

void set_conio_terminal_mode();

int kbhit();

int getch();
