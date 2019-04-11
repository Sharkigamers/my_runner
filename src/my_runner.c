/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** create a runner game
*/

#include "my.h"

int my_runner(char *filepath)
{
    window_t dwd;
    game_t game;
    music_t music;

    if (stock_map(filepath, &game) == 84)
        return (84);
    ini_all(&dwd, &game, &music);
    while (sfRenderWindow_isOpen(dwd.window)) {
        disp_menu(&dwd, &game, &music);
        parallax(&dwd);
        events(&dwd, &game, &music);
        disp_pause(&dwd, &game, &music);
        disp_over(&dwd, &music, &game);
        sfRenderWindow_display(dwd.window);
    }
    destroy_all(&dwd, &game, &music);
    return (0);
}
