/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** annex button
*/

#include "my.h"

void set_button_pause(window_t *dwd)
{
    dwd->menu.pause_t = sfTexture_createFromFile("assets/menu/pause.jpg", NULL);
    dwd->menu.pause_s = sfSprite_create();
    sfSprite_setTexture(dwd->menu.pause_s, dwd->menu.pause_t, sfTrue);
}

void action_return(game_t *game, window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        if (game->mouse.mouse_pos.x > 1200 && game->mouse.mouse_pos.x < 1730 &&
            game->mouse.mouse_pos.y > 805 && game->mouse.mouse_pos.y < 958) {
            dwd->menu.sec_button.rect_return.top = 530;
            dwd->menu.sec_button.rect_return.left = 1165;
            sfSprite_setTextureRect
            (dwd->menu.sec_button.return_s, dwd->menu.sec_button.rect_return);
        }
    }
    if (dwd->event.type == sfEvtMouseButtonReleased) {
        if (game->mouse.mouse_pos.x > 1200 && game->mouse.mouse_pos.x < 1730 &&
            game->mouse.mouse_pos.y > 805 && game->mouse.mouse_pos.y < 958) {
            sfMusic_play(music->click);
            dwd->menu.is_open = 1;
        }
    }
}

void cond_return(game_t *game, window_t *dwd, music_t *music)
{
    if (game->mouse.mouse_pos.x > 1200 && game->mouse.mouse_pos.x < 1730 &&
        game->mouse.mouse_pos.y > 805 && game->mouse.mouse_pos.y < 958) {
        dwd->menu.sec_button.rect_return.top = 526;
        dwd->menu.sec_button.rect_return.left = 0;
        sfSprite_setTextureRect
        (dwd->menu.sec_button.return_s, dwd->menu.sec_button.rect_return);
    }
    else {
        dwd->menu.sec_button.rect_return.top = 0;
        dwd->menu.sec_button.rect_return.left = 0;
        sfSprite_setTextureRect
        (dwd->menu.sec_button.return_s, dwd->menu.sec_button.rect_return);
    }
    action_return(game, dwd, music);
}

void disp_menu_button(window_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.play_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.shop_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.history_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.leave_s, NULL);
}
