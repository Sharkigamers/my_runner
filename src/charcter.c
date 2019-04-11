/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** character
*/

#include "my.h"

void set_character(game_t *game)
{
    game->chara.clock_chara = sfClock_create();
    game->chara.clock_jump = sfClock_create();
    game->chara.pos_champ.x = 75;
    game->chara.pos_champ.y = 610;
    game->chara.rect_champ.left = 0;
    game->chara.rect_champ.top = 10;
    game->chara.rect_champ.height = 200;
    game->chara.rect_champ.width = 140;
    game->chara.champ_t = sfTexture_createFromFile
        ("assets/gameplay/character.png", NULL);
    game->chara.champ_s = sfSprite_create();
    sfSprite_setTexture(game->chara.champ_s, game->chara.champ_t, sfTrue);
    sfSprite_setTextureRect(game->chara.champ_s, game->chara.rect_champ);
    sfSprite_setPosition(game->chara.champ_s, game->chara.pos_champ);
}

void clock_character(game_t *game)
{
    game->chara.time_chara = sfClock_getElapsedTime
        (game->chara.clock_chara);
    game->chara.sec_chara =
        game->chara.time_chara.microseconds / 1000000.0f;
}

void cond_disp_chara(game_t *game)
{
    if (game->chara.jump == 0) {
        if (game->chara.rect_champ.left < 1400)
            game->chara.rect_champ.left += 163;
        else
            game->chara.rect_champ.left = 0;
        sfSprite_setTextureRect(game->chara.champ_s, game->chara.rect_champ);
    }
    else if (game->chara.rect_champ.left < 500) {
        game->chara.rect_champ.left = 489;
        sfSprite_setTextureRect(game->chara.champ_s, game->chara.rect_champ);
    }
    else {
        game->chara.rect_champ.left = 1304;
        sfSprite_setTextureRect
            (game->chara.champ_s, game->chara.rect_champ);
    }
}

void display_character(game_t *game, window_t *dwd)
{
    clock_character(game);
    if (game->chara.sec_chara > 0.1) {
        cond_disp_chara(game);
        sfClock_restart(game->chara.clock_chara);
    }
    sfRenderWindow_drawSprite(dwd->window, game->chara.champ_s, NULL);
}
