/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** pause
*/

#include "my.h"

void sec_action_pause(game_t *game, window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtMouseButtonReleased) {
        if (game->mouse.mouse_pos.x > 675 && game->mouse.mouse_pos.x < 1185 &&
            game->mouse.mouse_pos.y > 510 && game->mouse.mouse_pos.y < 656) {
            sfMusic_play(music->click);
            dwd->menu.is_open = 1;
            dwd->menu.first_open = 0;
        }
    }
}

void action_pause(game_t *game, window_t *dwd, music_t *music)
{
    sec_action_pause(game, dwd, music);
    if (dwd->event.type == sfEvtMouseButtonPressed) {
        if (game->mouse.mouse_pos.x > 675 && game->mouse.mouse_pos.x < 1185 &&
            game->mouse.mouse_pos.y > 510 && game->mouse.mouse_pos.y < 656) {
            dwd->menu.button.rect_menu.left = 1722;
            dwd->menu.button.rect_menu.top = 365;
            sfSprite_setTextureRect
                (dwd->menu.button.menu_s, dwd->menu.button.rect_menu);
        }
    }
}

void cond_pause(game_t *game, window_t *dwd, music_t *music)
{
    dwd->menu.button.rect_menu.left = 566;
    dwd->menu.button.rect_menu.top = 368;
    action_pause(game, dwd, music);
    sfSprite_setTextureRect
        (dwd->menu.button.menu_s, dwd->menu.button.rect_menu);
}

void disp_pause(window_t *dwd, game_t *game, music_t *music)
{
    while (dwd->menu.is_open == 5) {
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.pause_s, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.menu_s, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.play_s, NULL);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            event_in_pause(dwd);
            cond_pause(game, dwd, music);
            cond_resume(game, dwd, music);
        }
        mouse(dwd, game);
        sfRenderWindow_display(dwd->window);
    }
}
