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



int main()
{
    int msec = 0;
    int trigger = 250; //milliseconds

    srandom(time(NULL));


    int fd, bytes;
    struct input_event data;

    const char *pDevice = "/dev/input/event0";
    short pressed = 0;

    // Open Keyboard
    fd = open(pDevice, O_RDONLY | O_NONBLOCK);
    if(fd == -1)
    {
        printf("ERROR Opening %s\ntry sudo ./tetris\n", pDevice);
        return -1;
    }


    struct game *game = game_init();

    print_map(game->map, game->cur_bloc);
    while (!update(game))
    {
        print_map(game->map, game->cur_bloc);
        clock_t before = clock();
        do
        {
            bytes = read(fd, &data, sizeof(data));
            if (bytes > 0)
            {
                int input = get_input(game, data.value, &pressed);
                if (input)
                {
                    print_map(game->map, game->cur_bloc);
                    if(input == 2)
                        break;
                }
            }

            clock_t difference = clock() - before;
            msec = difference * 1000 / CLOCKS_PER_SEC;

        } while (msec < trigger);
    }

    game_destroy(game);
    return 0;
}
