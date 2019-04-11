/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** button for menu
*/

#include "my.h"

void action_play(game_t *game, window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
        game->mouse.mouse_pos.y > 150 && game->mouse.mouse_pos.y < 318) {
        dwd->menu.button.rect_play.left = 1740;
        sfSprite_setTextureRect
            (dwd->menu.button.play_s, dwd->menu.button.rect_play);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
        game->mouse.mouse_pos.y > 150 && game->mouse.mouse_pos.y < 318) {
        load_skin(dwd, game);
        dwd->menu.is_open = 0;
        dwd->menu.button.pos_play.x = 650;
        dwd->menu.button.pos_play.y = 300;
        sfMusic_play(music->click);
        sfMusic_stop(music->menu);
        sfMusic_play(music->game);
        dwd->menu.first_open = 0;
    }
}

void cond_play(game_t *game, window_t *dwd, music_t *music)
{
    if (game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
        game->mouse.mouse_pos.y > 150 && game->mouse.mouse_pos.y < 318) {
        dwd->menu.button.rect_play.left = 571;
        sfSprite_setTextureRect
            (dwd->menu.button.play_s, dwd->menu.button.rect_play);
    } else {
        dwd->menu.button.rect_play.left = 0;
        sfSprite_setTextureRect
            (dwd->menu.button.play_s, dwd->menu.button.rect_play);
    }
    action_play(game, dwd, music);
    sfSprite_setPosition(dwd->menu.button.play_s, dwd->menu.button.pos_play);
}

void action_leave(game_t *game, window_t *dwd)
{
    if (dwd->event.type == sfEvtMouseButtonPressed &&
        game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
        game->mouse.mouse_pos.y > 760 && game->mouse.mouse_pos.y < 900) {
            dwd->menu.button.rect_leave.left = 1150;
            dwd->menu.button.rect_leave.top = 362;
            sfSprite_setTextureRect
                (dwd->menu.button.leave_s, dwd->menu.button.rect_leave);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
        game->mouse.mouse_pos.y > 760 && game->mouse.mouse_pos.y < 900) {
        dwd->menu.is_open = 0;
        sfRenderWindow_close(dwd->window);
    }
}

void cond_leave(game_t *game, window_t *dwd)
{
    if (game->mouse.mouse_pos.x > 1000 && game->mouse.mouse_pos.x < 1530 &&
        game->mouse.mouse_pos.y > 760 && game->mouse.mouse_pos.y < 900) {
        dwd->menu.button.rect_leave.top = 362;
        dwd->menu.button.rect_leave.left = 0;
        sfSprite_setTextureRect
        (dwd->menu.button.leave_s, dwd->menu.button.rect_leave);
    } else {
        dwd->menu.button.rect_leave.left = 0;
        dwd->menu.button.rect_leave.top = 0;
        sfSprite_setTextureRect
            (dwd->menu.button.leave_s, dwd->menu.button.rect_leave);
    }
    action_leave(game, dwd);
}
