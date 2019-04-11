/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** annex_menu
*/

#include "my.h"

void third_cond_ini_menu(game_t *game)
{
    int i = 0;

    for (; game->save_map[i] != '\0'; i++)
        game->map[i] = game->save_map[i];
    game->map[i] = '\0';
    game->score.pos_score.x = 420;
    game->score.pos_score.y = 820;
    game->score.pos_text.x = 50;
    game->score.pos_text.y = 820;
    game->hit.rect_hit.left = 0;
    game->hit.rect_hit.top = 0;
    game->hit.rect_hit.height = 142;
    game->hit.rect_hit.width = 137;
    sfSprite_setTextureRect(game->hit.hit_s, game->hit.rect_hit);
    sfText_setPosition(game->score.score_t, game->score.pos_score);
    sfText_setPosition(game->score.text_t, game->score.pos_text);
    sfText_setColor(game->score.score_t, sfRed);
    sfText_setColor(game->score.text_t, sfRed);
    game->hit.rect_hit.left = 0;
}

void sec_cond_ini_menu(window_t *dwd, game_t *game)
{
    dwd->menu.button.pos_menu.x = 650;
    dwd->menu.button.pos_menu.y = 500;
    sfSprite_setPosition(dwd->menu.button.menu_s, dwd->menu.button.pos_menu);
    dwd->over.open_over = 0;
    game->obs.pos_peak.x = 2000;
    game->obs.pos_house.x = 2000;
    game->obs.pos_zombie.x = 1000;
    sfSprite_setPosition(game->obs.zombie_s, game->obs.pos_zombie);
    sfSprite_setPosition(game->obs.house_s, game->obs.pos_house);
    sfSprite_setPosition(game->obs.peak_s, game->obs.pos_peak);
    game->score.score = 0;
}

void cond_ini_menu(window_t *dwd, game_t *game, music_t *music)
{
    game->obs.speed = 0;
    dwd->menu.button.rect_menu.left = 566;
    dwd->menu.button.rect_menu.top = 368;
    dwd->menu.button.pos_play.x = 1000;
    dwd->menu.button.pos_play.y = 150;
    dwd->menu.button.rect_play.left = 0;
    dwd->menu.button.rect_play.top = 0;
    dwd->menu.button.pos_menu.x = 650;
    dwd->menu.button.pos_menu.y = 500;
     sfSprite_setTextureRect
        (dwd->menu.button.menu_s, dwd->menu.button.rect_menu);
    sfSprite_setTextureRect
        (dwd->menu.button.play_s, dwd->menu.button.rect_play);
    sfSprite_setTextureRect
        (dwd->menu.button.menu_s, dwd->menu.button.rect_menu);
    sfSprite_setPosition
        (dwd->menu.button.play_s, dwd->menu.button.pos_play);
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.play_s, NULL);
    sfMusic_stop(music->game);
    sfMusic_play(music->menu);
}

void ini_menu(window_t *dwd, game_t *game, music_t *music)
{
    if (dwd->menu.first_open == 0) {
        dwd->menu.button.rect_play.left = 0;
        dwd->menu.button.rect_play.top = 0;
        sfSprite_setTextureRect
            (dwd->menu.button.play_s, dwd->menu.button.rect_play);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.play_s, NULL);
        game->chara.pos_champ.x = 75;
        game->chara.pos_champ.y = 610;
        game->chara.rect_champ.left = 0;
        game->chara.rect_champ.top = 10;
        game->chara.rect_champ.height = 200;
        game->chara.rect_champ.width = 140;
        sfSprite_setTextureRect(game->chara.champ_s, game->chara.rect_champ);
        sfSprite_setPosition(game->chara.champ_s, game->chara.pos_champ);
        cond_ini_menu(dwd, game, music);
        dwd->over.open_over = 0;
        sec_cond_ini_menu(dwd, game);
        third_cond_ini_menu(game);
        dwd->menu.first_open++;
    }
}
