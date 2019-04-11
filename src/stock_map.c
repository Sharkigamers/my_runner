/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** stock the map take as parameter
*/

#include "my.h"

void clock_obs(game_t *game)
{
    game->obs.time_obs = sfClock_getElapsedTime
        (game->obs.clock_obs);
    game->obs.sec_obs =
        game->obs.time_obs.microseconds / 1000000.0f;
}

void ini_map(game_t *game)
{
    game->obs.clock_obs = sfClock_create();
    game->obs.pos_peak.x = 400;
    game->obs.pos_peak.y = 729;
    game->obs.rect_peak.left = 0;
    game->obs.rect_peak.top = 0;
    game->obs.rect_peak.height = 72;
    game->obs.rect_peak.width = 80;
    game->obs.peak_t = sfTexture_createFromFile
        ("assets/gameplay/peak.png", NULL);
    game->obs.peak_s = sfSprite_create();
    sfSprite_setTexture(game->obs.peak_s, game->obs.peak_t, sfTrue);
    sfSprite_setTextureRect(game->obs.peak_s, game->obs.rect_peak);
    sfSprite_setPosition(game->obs.peak_s, game->obs.pos_peak);
    game->obs.pos_house.x = 400;
    game->obs.pos_house.y = 270;
    game->obs.house_t = sfTexture_createFromFile
        ("assets/gameplay/house.png", NULL);
    game->obs.house_s = sfSprite_create();
    sfSprite_setTexture(game->obs.house_s, game->obs.house_t, sfTrue);
    sfSprite_setPosition(game->obs.house_s, game->obs.pos_house);
}

void fill_map(char *filepath, game_t *game, int total_len)
{
    FILE *fd = fopen(filepath, "r");
    char *buffer = NULL;
    ssize_t len = 0;
    size_t sz = 0;
    int i = 0;

    game->map = malloc(total_len + 1);
    game->save_map = malloc(total_len + 1);
    while ((len  = getline(&buffer, &sz, fd)) > 0) {
        for (int j = 0; buffer[j] != '\0'; j++, i++) {
            game->map[i] = buffer[j];
            game->save_map[i] = game->map[j];
        }
    }
    game->map[total_len] = '\0';
    game->save_map[total_len] = '\0';
    fclose(fd);
}

int stock_map(char *filepath, game_t *game)
{
    FILE *fd = fopen(filepath, "r");
    char *buffer = NULL;
    ssize_t len = 0;
    size_t sz = 0;
    int total_len = 0;

    if (fd == NULL) {
        write(2, "Error encountered with the map took as parameter.\n", 51);
        write(2, "Check: ./my_runner -h\n", 23);
        return (84);
    }
    while ((len  = getline(&buffer, &sz, fd)) > 0)
        total_len += len;
    if (total_len == 0) {
        write(2, "You have chosen an empty map ! Change it !", 43);
        return (84);
    }
    fclose(fd);
    fill_map(filepath, game, total_len);
    return (0);
}

void disp_obs(game_t *game)
{
    clock_obs(game);
    if (game->obs.sec_obs > 0.1) {
        game->obs.speed += 3;
    }
}
