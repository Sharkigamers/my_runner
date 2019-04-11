/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** main event
*/

#include "my.h"

void in_event(window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtClosed)
        sfRenderWindow_close(dwd->window);
    if (dwd->event.type == sfEvtKeyPressed) {
        if (dwd->event.key.code == sfKeyEscape) {
            sfMusic_play(music->click);
            dwd->menu.is_open = 5;
        }
    }
}

void events(window_t *dwd, game_t *game, music_t *music)
{
    display_character(game, dwd);
    if (dwd->event.type == sfEvtMouseButtonReleased)
        game->hit.kill = 0;
    disp_obs(game);
    disp_map(game, dwd, music);
    score_progress(game, dwd);
    sfRenderWindow_drawSprite(dwd->window, game->obs.zombie_s, NULL);
    mouse(dwd, game);
    jump(game, dwd);
    hit(game, dwd, music);
    if (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
        in_event(dwd, music);
    }
}
