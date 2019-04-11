/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** event for character
*/

#include "my.h"

void clock_jump(game_t *game)
{
    game->chara.time_jump = sfClock_getElapsedTime
        (game->chara.clock_jump);
    game->chara.sec_jump =
        game->chara.time_jump.microseconds / 1000000.0f;
}

void cond_jump(game_t *game)
{
    if (game->chara.jump == 1) {
        game->chara.pos_champ.y -= 5;
        sfSprite_setPosition(game->chara.champ_s, game->chara.pos_champ);
    }
    if (game->chara.jump == 2) {
        game->chara.pos_champ.y += 6;
        sfSprite_setPosition(game->chara.champ_s, game->chara.pos_champ);
    }
}

void jump(game_t *game, window_t *dwd)
{
    clock_jump(game);
    if (game->chara.pos_champ.y == 610)
        game->chara.jump = 0;
    if (game->chara.pos_champ.y == 400)
        game->chara.jump = 2;
    if (dwd->event.type == sfEvtKeyPressed) {
        if (dwd->event.key.code == sfKeySpace && game->chara.jump == 0)
            game->chara.jump = 1;
    }
    if (game->chara.sec_jump > 0.1)
        cond_jump(game);
}
