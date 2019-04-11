/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** annex for game over
*/

#include "my.h"

void sec_ini_over_menu(window_t *dwd, game_t *game)
{
    if (dwd->over.open_over == 4) {
        game->score.pos_score.x = 1100;
        game->score.pos_score.y = 500;
        game->score.pos_text.x = 700;
        game->score.pos_text.y = 500;
    }
    sfText_setColor(game->score.score_t, sfWhite);
    sfText_setColor(game->score.text_t, sfWhite);
    sfText_setPosition(game->score.score_t, game->score.pos_score);
    sfText_setPosition(game->score.text_t, game->score.pos_text);
}

void ini_over_menu(window_t *dwd, game_t *game)
{
    if (dwd->menu.first_open == 0) {
        stock_highest_score(game);
        dwd->menu.button.pos_menu.x = 1150;
        dwd->menu.button.pos_menu.y = 800;
        dwd->menu.button.rect_menu.top = 0;
        dwd->menu.button.rect_menu.left = 0;
        sfSprite_setTextureRect
            (dwd->menu.button.menu_s, dwd->menu.button.rect_menu);
        sfSprite_setPosition
            (dwd->menu.button.menu_s, dwd->menu.button.pos_menu);
        game->score.pos_score.x = 550;
        game->score.pos_score.y = 600;
        game->score.pos_text.x = 200;
        game->score.pos_text.y = 600;
        sec_ini_over_menu(dwd, game);
        dwd->menu.first_open++;
    }
}
