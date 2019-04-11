/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** music and sounds
*/

#include "my.h"

void ini_music(music_t *music)
{
    music->menu = sfMusic_createFromFile("assets/music/menu.ogg");
    music->game = sfMusic_createFromFile("assets/music/game.ogg");
    music->click = sfMusic_createFromFile("assets/music/click.ogg");
    music->sword = sfMusic_createFromFile("assets/music/sword.ogg");
    music->shoot = sfMusic_createFromFile("assets/music/shoot.ogg");
}
