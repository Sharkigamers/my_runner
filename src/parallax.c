/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** parallax
*/

#include "my.h"

void clock_parallax(window_t *dwd)
{
    dwd->parallax.time_paral = sfClock_getElapsedTime
        (dwd->parallax.clock_paral);
    dwd->parallax.sec_paral =
        dwd->parallax.time_paral.microseconds / 1000000.0f;
}

void set_parallax(window_t *dwd)
{
    dwd->parallax.clock_paral = sfClock_create();
    dwd->parallax.ground_t = sfTexture_createFromFile
        ("assets/bck/bck_1.png", NULL);
    dwd->parallax.trees_t = sfTexture_createFromFile
        ("assets/bck/bck_2.png", NULL);
    dwd->parallax.forest_t = sfTexture_createFromFile
        ("assets/bck/bck_2_5.png", NULL);
    dwd->parallax.sky_t = sfTexture_createFromFile
        ("assets/bck/bck_3.jpg", NULL);
    dwd->parallax.fog_t = sfTexture_createFromFile("assets/bck/fog.png", NULL);
    dwd->parallax.ground_s = sfSprite_create();
    dwd->parallax.trees_s = sfSprite_create();
    dwd->parallax.forest_s = sfSprite_create();
    dwd->parallax.sky_s = sfSprite_create();
    dwd->parallax.fog_s = sfSprite_create();
    sfSprite_setTexture(dwd->parallax.ground_s, dwd->parallax.ground_t, sfTrue);
    sfSprite_setTexture(dwd->parallax.trees_s, dwd->parallax.trees_t, sfTrue);
    sfSprite_setTexture(dwd->parallax.forest_s, dwd->parallax.forest_t, sfTrue);
    sfSprite_setTexture(dwd->parallax.sky_s, dwd->parallax.sky_t, sfTrue);
    sfSprite_setTexture(dwd->parallax.fog_s, dwd->parallax.fog_t, sfTrue);
}

void parallax_cond2(window_t *dwd)
{
    if (sfSprite_getPosition(dwd->parallax.forest_s).x > -1920) {
        sfSprite_setPosition(dwd->parallax.forest_s,
                            dwd->parallax.pos_forest);
        dwd->parallax.pos_forest.x -= 0.5;
    }
    if (sfSprite_getPosition(dwd->parallax.forest_s).x <= -1920) {
        dwd->parallax.pos_forest.x = 0;
        sfSprite_setPosition(dwd->parallax.forest_s,
                            dwd->parallax.pos_forest);
    }
    if (sfSprite_getPosition(dwd->parallax.fog_s).x > -3840) {
        sfSprite_setPosition(dwd->parallax.fog_s,
                            dwd->parallax.pos_fog);
        dwd->parallax.pos_fog.x -= 1;
    }
    if (sfSprite_getPosition(dwd->parallax.fog_s).x <= -3840) {
        dwd->parallax.pos_fog.x = 0;
        sfSprite_setPosition(dwd->parallax.fog_s,
                            dwd->parallax.pos_fog);
    }
}

void parallax_cond(window_t *dwd)
{
    if (sfSprite_getPosition(dwd->parallax.ground_s).x > -1920) {
        sfSprite_setPosition(dwd->parallax.ground_s,
                            dwd->parallax.pos_ground);
        dwd->parallax.pos_ground.x -= 3;
    }
    if (sfSprite_getPosition(dwd->parallax.ground_s).x <= -1920) {
        dwd->parallax.pos_ground.x = 0;
        sfSprite_setPosition(dwd->parallax.ground_s,
                            dwd->parallax.pos_ground);
    }
    if (sfSprite_getPosition(dwd->parallax.trees_s).x > -1920) {
        sfSprite_setPosition(dwd->parallax.trees_s,
                            dwd->parallax.pos_trees);
        dwd->parallax.pos_trees.x -= 1;
    }
    if (sfSprite_getPosition(dwd->parallax.trees_s).x <= -1920) {
        dwd->parallax.pos_trees.x = 0;
        sfSprite_setPosition(dwd->parallax.trees_s,
                            dwd->parallax.pos_trees);
    }
}

void parallax(window_t *dwd)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->parallax.sky_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->parallax.forest_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->parallax.trees_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->parallax.fog_s, NULL);
    sfRenderWindow_drawSprite(dwd->window, dwd->parallax.ground_s, NULL);
    clock_parallax(dwd);
    if (dwd->parallax.sec_paral > 0.1) {
        parallax_cond(dwd);
        parallax_cond2(dwd);
    }
}
