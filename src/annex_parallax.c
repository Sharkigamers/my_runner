/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** annex for the parallax
*/

#include "my.h"

void ini_pos_parallax(window_t *dwd)
{
    dwd->parallax.forest_s.x = 0;
    dwd->parallax.fog_s.x = 0;
    dwd->parallax.ground_s.x = 0;
    dwd->parallax.trees_s.x = 0;
    sfSprite_setPosition(dwd->parallax.forest_s,
                            dwd->parallax.pos_forest);
    sfSprite_setPosition(dwd->parallax.fog_s,
                            dwd->parallax.pos_fog);
    sfSprite_setPosition(dwd->parallax.ground_s,
                            dwd->parallax.pos_ground);
    sfSprite_setPosition(dwd->parallax.trees_s,
                            dwd->parallax.pos_trees);
}
