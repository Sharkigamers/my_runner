/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** story of the game
*/

#include "my.h"

void event_in_history(window_t *dwd)
{
    if (dwd->event.type == sfEvtClosed) {
        sfRenderWindow_close(dwd->window);
        dwd->menu.is_open = 0;
    }
}

void disp_history(window_t *dwd, game_t *game, music_t *music)
{
    while (dwd->menu.is_open == 3) {
        cond_return(game, dwd, music);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.story_s, NULL);
        sfRenderWindow_drawSprite
            (dwd->window, dwd->menu.sec_button.return_s, NULL);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            event_in_history(dwd);
        }
        mouse(dwd, game);
        sfRenderWindow_display(dwd->window);
    }
}
