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
        clock_t before = clock();
        do
        {
            bytes = read(fd, &data, sizeof(data));
            if(bytes > 0)
            {
                if (data.value == 205 || data.value == 203
                    || data.value == 200)
                {
                    if (pressed)
                        pressed = 0;
                    else
                    {
                        pressed = 1;
                        if (data.value == 200)
                        {
                            if (!bloc_rotate(game))
                                print_map(game->map, game->cur_bloc);
                        }

                        else if (data.value == 208)
                            data.value = data.value; //TODO

                        else if (!bloc_move(game, (data.value == 203)))
                            print_map(game->map, game->cur_bloc);
                    }
                }
//                printf("type: %d\ncode: %d\n\n", data.type, data.code);
            }

            clock_t difference = clock() - before;
            msec = difference * 1000 / CLOCKS_PER_SEC;

        } while (msec < trigger);


        print_map(game->map, game->cur_bloc);
//        printf("rot: %d\n", game->cur_bloc->rot);
    }

    game_destroy(game);
    return 0;
}
