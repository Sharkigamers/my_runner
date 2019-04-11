/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** mouse cursor
*/

#include "my.h"

void ini_mouse(game_t *game)
{
    game->mouse.mouse_t = sfTexture_createFromFile
        ("assets/gameplay/mouse.png", NULL);
    game->mouse.mouse_s = sfSprite_create();
    sfSprite_setTexture(game->mouse.mouse_s, game->mouse.mouse_t, sfTrue);
}

void mouse(window_t *dwd, game_t *game)
{
    game->mouse.mouse_pos = sfMouse_getPositionRenderWindow(dwd->window);
    game->mouse.pos.x = game->mouse.mouse_pos.x;
    game->mouse.pos.y = game->mouse.mouse_pos.y;
    sfSprite_setPosition(game->mouse.mouse_s, game->mouse.pos);
    sfRenderWindow_drawSprite(dwd->window, game->mouse.mouse_s, NULL);
}
