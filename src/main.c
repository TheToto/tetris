#include "tetris.h"


void sleep_ms(int milliseconds) // cross-platform sleep function
{
#if _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    usleep(milliseconds * 1000);
#endif
}

int get_input(void)
{
    return 0;
}


int main()
{
    int msec = 0;
    int trigger = 250; //milliseconds

    clock_t before = clock();
    set_conio_terminal_mode();
    srandom(time(NULL));

    struct game *game = game_init();


    while (!kbhit() && msec < trigger)
    {
        clock_t difference = clock() - before;
        msec = difference * 1000 / CLOCKS_PER_SEC;



    }
    (void)getch(); /* consume the character */


    while (!update(game))
    {
        char c = 0;

        if(kbhit()){
            c = getch();
            printf("%c\n", c);
        }

        print_map(game->map, game->cur_bloc);
        sleep_ms(250);
    }
    
    game_destroy(game);
    return 0;
}
