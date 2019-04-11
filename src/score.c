/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** score
*/

#include "my.h"

void score(game_t *game)
{
    game->score.score = 0;
    game->score.score_f = sfFont_createFromFile
        ("assets/text/youmurdererbb_reg.ttf");
    game->score.text_f = sfFont_createFromFile
        ("assets/text/youmurdererbb_reg.ttf");
    game->score.score_t = sfText_create();
    game->score.text_t = sfText_create();
    sfText_setFont(game->score.score_t, game->score.score_f);
    sfText_setColor(game->score.score_t, sfRed);
    sfText_setFont(game->score.text_t, game->score.text_f);
    sfText_setColor(game->score.text_t, sfRed);
    game->score.pos_score.x = 420;
    game->score.pos_score.y = 820;
    game->score.pos_text.x = 50;
    game->score.pos_text.y = 820;
    sfText_setCharacterSize(game->score.score_t, 150);
    sfText_setCharacterSize(game->score.text_t, 150);
    sfText_setString(game->score.text_t, "Score :");
    sfText_setPosition(game->score.score_t, game->score.pos_score);
    sfText_setPosition(game->score.text_t, game->score.pos_text);
}

void hight_score(game_t *game)
{
    game->hscore.hscore_f = sfFont_createFromFile
        ("assets/text/youmurdererbb_reg.ttf");
    game->hscore.htext_f = sfFont_createFromFile
        ("assets/text/youmurdererbb_reg.ttf");
    game->hscore.hscore_t = sfText_create();
    game->hscore.htext_t = sfText_create();
    sfText_setFont(game->hscore.hscore_t, game->hscore.hscore_f);
    sfText_setColor(game->hscore.hscore_t, sfRed);
    sfText_setFont(game->hscore.htext_t, game->hscore.htext_f);
    sfText_setColor(game->hscore.htext_t, sfRed);
    game->hscore.pos_hscore.x = 150;
    game->hscore.pos_hscore.y = 250;
    game->hscore.pos_htext.x = 150;
    game->hscore.pos_htext.y = 100;
    sfText_setCharacterSize(game->hscore.hscore_t, 150);
    sfText_setCharacterSize(game->hscore.htext_t, 150);
    sfText_setString(game->hscore.htext_t, "Highest score :");
    sfText_setPosition(game->hscore.hscore_t, game->hscore.pos_hscore);
    sfText_setPosition(game->hscore.htext_t, game->hscore.pos_htext);
}

void clock_score(game_t *game)
{
    game->score.time_score = sfClock_getElapsedTime
        (game->score.clock_score);
    game->score.sec_score =
        game->score.time_score.microseconds / 1000000.0f;
}

void score_progress(game_t *game, window_t *dwd)
{
    clock_score(game);
    if (game->score.sec_score > 1) {
        game->score.score += 3;
        sfClock_restart(game->score.clock_score);
    }
    sfText_setString(game->score.score_t, my_itoa(game->score.score));
    sfRenderWindow_drawText(dwd->window, game->score.text_t, NULL);
    sfRenderWindow_drawText(dwd->window, game->score.score_t, NULL);
}
