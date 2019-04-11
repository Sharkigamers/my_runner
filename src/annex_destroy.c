/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** annex for destroy
*/

#include "my.h"

void destroy_more_gameplay(game_t *game)
{
    sfClock_destroy(game->obs.clock_obs);
    sfTexture_destroy(game->obs.peak_t);
    sfSprite_destroy(game->obs.peak_s);
    sfTexture_destroy(game->obs.zombie_t);
    sfSprite_destroy(game->obs.zombie_s);
    sfTexture_destroy(game->obs.house_t);
    sfSprite_destroy(game->obs.house_s);
    free(game->map);
    free(game->save_map);
}
