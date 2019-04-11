/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** destroy all
*/

#include "my.h"

void destroy_music(music_t *music)
{
    sfMusic_stop(music->menu);
    sfMusic_stop(music->game);
    sfMusic_stop(music->click);
    sfMusic_stop(music->sword);
    sfMusic_stop(music->shoot);
    sfMusic_destroy(music->menu);
    sfMusic_destroy(music->game);
    sfMusic_destroy(music->click);
    sfMusic_destroy(music->sword);
    sfMusic_destroy(music->shoot);
}

void cond_destroy_window(window_t *dwd)
{
    sfTexture_destroy(dwd->over.szover_t);
    sfSprite_destroy(dwd->over.szover_s);
    sfTexture_destroy(dwd->menu.menu_t);
    sfTexture_destroy(dwd->menu.story_t);
    sfSprite_destroy(dwd->menu.menu_s);
    sfSprite_destroy(dwd->menu.story_s);
    sfTexture_destroy(dwd->menu.button.play_t);
    sfTexture_destroy(dwd->menu.button.shop_t);
    sfTexture_destroy(dwd->menu.button.history_t);
    sfTexture_destroy(dwd->menu.button.leave_t);
    sfTexture_destroy(dwd->menu.button.menu_t);
    sfSprite_destroy(dwd->menu.button.play_s);
    sfSprite_destroy(dwd->menu.button.shop_s);
    sfSprite_destroy(dwd->menu.button.history_s);
    sfSprite_destroy(dwd->menu.button.leave_s);
    sfTexture_destroy(dwd->menu.sec_button.return_t);
    sfSprite_destroy(dwd->menu.sec_button.return_s);
}

void destroy_window(window_t *dwd)
{
    sfTexture_destroy(dwd->over.tover_t);
    sfSprite_destroy(dwd->over.tover_s);
    sfTexture_destroy(dwd->parallax.ground_t);
    sfTexture_destroy(dwd->parallax.trees_t);
    sfTexture_destroy(dwd->parallax.forest_t);
    sfTexture_destroy(dwd->parallax.sky_t);
    sfTexture_destroy(dwd->parallax.fog_t);
    sfSprite_destroy(dwd->parallax.ground_s);
    sfSprite_destroy(dwd->parallax.trees_s);
    sfSprite_destroy(dwd->parallax.forest_s);
    sfSprite_destroy(dwd->parallax.sky_s);
    sfSprite_destroy(dwd->parallax.fog_s);
    sfClock_destroy(dwd->parallax.clock_paral);
    sfTexture_destroy(dwd->menu.shop.shop_t);
    sfTexture_destroy(dwd->menu.shop.wood_t);
    sfTexture_destroy(dwd->menu.shop.diam_t);
    sfSprite_destroy(dwd->menu.shop.shop_s);
    sfSprite_destroy(dwd->menu.shop.wood_s);
    sfSprite_destroy(dwd->menu.shop.diam_s);
    cond_destroy_window(dwd);
}

void destroy_gameplay(game_t *game)
{
    sfTexture_destroy(game->mouse.mouse_t);
    sfSprite_destroy(game->mouse.mouse_s);
    sfTexture_destroy(game->chara.champ_t);
    sfSprite_destroy(game->chara.champ_s);
    sfClock_destroy(game->chara.clock_chara);
    sfClock_destroy(game->chara.clock_jump);
    sfText_destroy(game->hscore.hscore_t);
    sfFont_destroy(game->hscore.hscore_f);
    sfText_destroy(game->score.score_t);
    sfFont_destroy(game->score.score_f);
    sfText_destroy(game->hscore.htext_t);
    sfFont_destroy(game->hscore.htext_f);
    sfText_destroy(game->score.text_t);
    sfFont_destroy(game->score.text_f);
    sfTexture_destroy(game->hit.hit_t);
    sfSprite_destroy(game->hit.hit_s);
    destroy_more_gameplay(game);
}

void destroy_all(window_t *dwd, game_t *game, music_t *music)
{
    sfTexture_destroy(dwd->over.zover_t);
    sfSprite_destroy(dwd->over.zover_s);
    sfTexture_destroy(dwd->over.victory_t);
    sfSprite_destroy(dwd->over.victory_s);
    destroy_music(music);
    destroy_window(dwd);
    destroy_gameplay(game);
}
