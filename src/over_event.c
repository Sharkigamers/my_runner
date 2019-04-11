/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** event over
*/

#include "my.h"

void action_over_menu(game_t *game, window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        if (game->mouse.mouse_pos.x > 1175 && game->mouse.mouse_pos.x < 1665 &&
            game->mouse.mouse_pos.y > 811 && game->mouse.mouse_pos.y < 950) {
            dwd->menu.button.rect_menu.left = 1722;
            dwd->menu.button.rect_menu.top = 365;
            sfSprite_setTextureRect
                (dwd->menu.button.menu_s, dwd->menu.button.rect_menu);
        }
    }
    if (dwd->event.type == sfEvtMouseButtonReleased) {
        if (game->mouse.mouse_pos.x > 1175 && game->mouse.mouse_pos.x < 1665 &&
            game->mouse.mouse_pos.y > 811 && game->mouse.mouse_pos.y < 950) {
            sfMusic_play(music->click);
            dwd->menu.button.rect_menu.left = 566;
            dwd->menu.button.rect_menu.top = 368;
            dwd->menu.first_open = 0;
            dwd->over.open_over = 0;
            dwd->menu.is_open = 1;
        }
    }
}

void cond_over_menu(game_t *game, window_t *dwd, music_t *music)
{
    if (game->mouse.mouse_pos.x > 1175 && game->mouse.mouse_pos.x < 1665 &&
        game->mouse.mouse_pos.y > 811 && game->mouse.mouse_pos.y < 950) {
        dwd->menu.button.rect_menu.left = 566;
        dwd->menu.button.rect_menu.top = 368;
        sfSprite_setTextureRect
            (dwd->menu.button.menu_s, dwd->menu.button.rect_menu);
    }
    else {
        dwd->menu.button.rect_menu.top = 0;
        dwd->menu.button.rect_menu.left = 0;
        sfSprite_setTextureRect
            (dwd->menu.button.menu_s, dwd->menu.button.rect_menu);
    }
    action_over_menu(game, dwd, music);
}
