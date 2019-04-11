/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** second part of button for menu
*/

#include "my.h"

void action_shop(game_t *game, window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        if (game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
            game->mouse.mouse_pos.y > 360 && game->mouse.mouse_pos.y < 500) {
            dwd->menu.button.rect_shop.left = 1722;
            dwd->menu.button.rect_shop.top = 206;
            sfSprite_setTextureRect
                (dwd->menu.button.shop_s, dwd->menu.button.rect_shop);
        }
    }
    if (dwd->event.type == sfEvtMouseButtonReleased) {
        if (game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
            game->mouse.mouse_pos.y > 360 && game->mouse.mouse_pos.y < 500) {
            sfMusic_play(music->click);
            dwd->menu.is_open = 4;
            dwd->menu.button.rect_shop.left = 0;
            dwd->menu.button.rect_shop.top = 0;
            sfSprite_setTextureRect
                (dwd->menu.button.shop_s, dwd->menu.button.rect_shop);
        }
    }
}

void cond_shop(game_t *game, window_t *dwd, music_t *music)
{
    if (game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
        game->mouse.mouse_pos.y > 360 && game->mouse.mouse_pos.y < 500) {
        dwd->menu.button.rect_shop.top = 206;
        dwd->menu.button.rect_shop.left = 570;
        sfSprite_setTextureRect
            (dwd->menu.button.shop_s, dwd->menu.button.rect_shop);
    } else {
        dwd->menu.button.rect_shop.left = 0;
        dwd->menu.button.rect_shop.top = 0;
        sfSprite_setTextureRect
            (dwd->menu.button.shop_s, dwd->menu.button.rect_shop);
    }
    action_shop(game, dwd, music);
}

void action_history(game_t *game, window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        if (game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
            game->mouse.mouse_pos.y > 560 && game->mouse.mouse_pos.y < 700) {
            dwd->menu.button.rect_history.left = 1170;
            dwd->menu.button.rect_history.top = 203;
            sfSprite_setTextureRect
                (dwd->menu.button.history_s, dwd->menu.button.rect_history);
        }
    }
    if (dwd->event.type == sfEvtMouseButtonReleased) {
        if (game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
            game->mouse.mouse_pos.y > 560 && game->mouse.mouse_pos.y < 700) {
            sfMusic_play(music->click);
            dwd->menu.is_open = 3;
            dwd->menu.button.rect_history.left = 0;
            dwd->menu.button.rect_history.top = 0;
            sfSprite_setTextureRect
                (dwd->menu.button.history_s, dwd->menu.button.rect_history);
        }
    }
}

void cond_history(game_t *game, window_t *dwd, music_t *music)
{
    if (game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
        game->mouse.mouse_pos.y > 560 && game->mouse.mouse_pos.y < 700) {
        dwd->menu.button.rect_history.top = 203;
        dwd->menu.button.rect_history.left = 0;
        sfSprite_setTextureRect
            (dwd->menu.button.history_s, dwd->menu.button.rect_history);
    } else {
        dwd->menu.button.rect_history.left = 0;
        dwd->menu.button.rect_history.top = 0;
        sfSprite_setTextureRect
            (dwd->menu.button.history_s, dwd->menu.button.rect_history);
    }
    action_history(game, dwd, music);
}
