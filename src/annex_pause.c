/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** annex_pause
*/

#include "my.h"

void sec_action_resume(game_t *game, window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtMouseButtonReleased) {
        if (game->mouse.mouse_pos.x > 675 && game->mouse.mouse_pos.x < 1185 &&
            game->mouse.mouse_pos.y > 310 && game->mouse.mouse_pos.y < 456) {
            sfMusic_play(music->click);
            dwd->menu.is_open = 0;
            dwd->menu.button.rect_play.left = 571;
            dwd->menu.button.rect_play.top = 0;
            sfSprite_setTextureRect
                (dwd->menu.button.play_s, dwd->menu.button.rect_play);
        }
    }
}

void action_resume(game_t *game, window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        if (game->mouse.mouse_pos.x > 675 && game->mouse.mouse_pos.x < 1185 &&
            game->mouse.mouse_pos.y > 310 && game->mouse.mouse_pos.y < 456) {
            dwd->menu.button.rect_play.left = 1722;
            dwd->menu.button.rect_play.top = 0;
            sfSprite_setTextureRect
                (dwd->menu.button.play_s, dwd->menu.button.rect_play);
        }
    }
    sec_action_resume(game, dwd, music);
}

void cond_resume(game_t *game, window_t *dwd, music_t *music)
{
    dwd->menu.button.rect_play.left = 571;
    dwd->menu.button.rect_play.top = 0;
    action_resume(game, dwd, music);
    sfSprite_setTextureRect
        (dwd->menu.button.play_s, dwd->menu.button.rect_play);
}

void event_in_pause(window_t *dwd)
{
    if (dwd->event.type == sfEvtClosed) {
        sfRenderWindow_close(dwd->window);
        dwd->menu.is_open = 0;
    }
    if (dwd->event.type == sfEvtKeyPressed) {
        if (dwd->event.key.code == sfKeyEscape)
            dwd->menu.is_open = 0;
    }
}
