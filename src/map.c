/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** map
*/

#include "my.h"

void cond_zombie(game_t *game, window_t *dwd)
{
    for (int j = 0; game->map[j] != '\0'; j++) {
        if (game->map[j] == 'z') {
            game->map[j] = ' ';
            game->obs.pos_zombie.x = -3000;
            sfSprite_setPosition(game->obs.zombie_s, game->obs.pos_zombie);
            sfRenderWindow_drawSprite(dwd->window, game->obs.zombie_s, NULL);
            game->score.score += 15;
            game->hit.kill = 1;
            return;
        }
    }
}

void hit_box_zombie(game_t *game, window_t *dwd, music_t *music)
{
    sfVector2f chara = sfSprite_getPosition(game->chara.champ_s);
    sfVector2f hit = sfSprite_getPosition(game->hit.hit_s);
    sfVector2f zombie = game->obs.pos_zombie;

    if (dwd->event.type == sfEvtMouseButtonPressed && game->hit.kill == 0 &&
        ((hit.x + 137) >= zombie.x && (hit.x + 137) <= (zombie.x + 150))) {
        cond_zombie(game, dwd);
    }
    if (((chara.y + 166) >= (zombie.y + 75) && (chara.y + 166) <= 1080) &&
        ((chara.x + 32) >= zombie.x && (chara.x + 32) <= (zombie.x + 150))) {
        dwd->over.open_over = 1;
        sfMusic_stop(music->game);
        sfMusic_play(music->menu);
    }
}

void hit_box(game_t *game, window_t *dwd, music_t *music)
{
    sfVector2f chara = sfSprite_getPosition(game->chara.champ_s);
    sfVector2f house = game->obs.pos_house;
    sfVector2f pic = game->obs.pos_peak;

    if (((chara.y + 166) >= (pic.y + 33) && (chara.y + 166) <= (pic.y + 52)) &&
        (((chara.x + 32) >= (pic.x + 4) && (chara.x + 32) <= (pic.x + 72)) ||
        ((chara.x + 124) >= (pic.x + 4) && (chara.x + 124) <= (pic.x + 72)))) {
        dwd->over.open_over = 3;
        sfMusic_stop(music->game);
        sfMusic_play(music->menu);
    }
    if (((chara.y + 166) >= 0 && (chara.y + 166) <= 1080) &&
        ((chara.x + 32) >= (house.x + 96))) {
        dwd->over.open_over = 4;
        game->score.score += 2;
        sfMusic_stop(music->game);
        sfMusic_play(music->menu);
    }
    hit_box_zombie(game, dwd, music);
}

void disp_map(game_t *game, window_t *dwd, music_t *music)
{
    for (int i = 0; game->map[i] != '\0'; i++) {
        hit_box(game, dwd, music);
        if (game->map[i] == 'p') {
            game->obs.pos_peak.x = i * 100 - game->obs.speed;
            sfSprite_setPosition(game->obs.peak_s, game->obs.pos_peak);
            sfRenderWindow_drawSprite(dwd->window, game->obs.peak_s, NULL);
        }
        if (game->map[i] == 'e') {
            game->obs.pos_house.x = i * 100 - game->obs.speed;
            sfSprite_setPosition(game->obs.house_s, game->obs.pos_house);
            sfRenderWindow_drawSprite(dwd->window, game->obs.house_s, NULL);
        }
        if (game->map[i] == 'z') {
            game->obs.pos_zombie.x = i * 100 - game->obs.speed;
            sfSprite_setPosition(game->obs.zombie_s, game->obs.pos_zombie);
            sfRenderWindow_drawSprite(dwd->window, game->obs.zombie_s, NULL);
        }
    }
}
