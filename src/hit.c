/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** hit
*/

#include "my.h"

void ini_hit(game_t *game)
{
    game->hit.nb_hit = 0;
    game->hit.is_click = 0;
    game->hit.hit_t = sfTexture_createFromFile("assets/gameplay/hit.png", NULL);
    game->hit.hit_s = sfSprite_create();
    sfSprite_setTexture(game->hit.hit_s, game->hit.hit_t, sfTrue);
    game->hit.rect_hit.left = 0;
    game->hit.rect_hit.top = 0;
    game->hit.rect_hit.height = 142;
    game->hit.rect_hit.width = 137;
    game->hit.pos_hit.x = 155;
    game->hit.pos_hit.y = 620;
    sfSprite_setPosition(game->hit.hit_s, game->hit.pos_hit);
}

void nb_clic(game_t *game)
{
    switch (game->hit.nb_hit) {
    case 0:
        game->hit.rect_hit.top = 0;
        break;
    case 1:
        game->hit.rect_hit.top += 142;
        break;
    case 2:
        game->hit.rect_hit.top += 142;
        break;
    case 3:
        game->hit.rect_hit.top += 142;
        break;
    }
}

void hit(game_t *game, window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtMouseButtonPressed && game->chara.jump == 0 &&
        game->hit.is_click == 0) {
        game->hit.is_click = 1;
        game->hit.nb_hit += 1;
        game->hit.nb_hit == 4 ? game->hit.nb_hit = 0 : 0;
        nb_clic(game);
        sfMusic_play(music->sword);
    }
    if (game->hit.is_click == 1) {
        game->chara.sec_chara > 0.1 ? game->hit.rect_hit.left += 137 : 0;
        sfSprite_setTextureRect
            (game->hit.hit_s, game->hit.rect_hit);
        sfRenderWindow_drawSprite(dwd->window, game->hit.hit_s, NULL);
    }
    if (dwd->event.type == sfEvtMouseButtonReleased &&
        game->hit.rect_hit.left > 560) {
        game->hit.is_click = 0;
        game->hit.rect_hit.left = 0;
    }
}
