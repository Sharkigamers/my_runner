/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** create zombie
*/

#include "my.h"

void ini_zombie(game_t *game)
{
    game->obs.clock_obs = sfClock_create();
    game->obs.zombie_t = sfTexture_createFromFile
        ("assets/gameplay/zombie.png", NULL);
    game->obs.zombie_s = sfSprite_create();
    game->obs.rect_zombie.left = 330;
    game->obs.rect_zombie.top = 440;
    game->obs.rect_zombie.height = 200;
    game->obs.rect_zombie.width = 170;
    game->obs.pos_zombie.x = 1000;
    game->obs.pos_zombie.y = 585;
    sfSprite_setTexture(game->obs.zombie_s, game->obs.zombie_t, sfTrue);
    sfSprite_setTextureRect(game->obs.zombie_s, game->obs.rect_zombie);
    sfSprite_setPosition(game->obs.zombie_s, game->obs.pos_zombie);
}
