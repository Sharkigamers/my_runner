/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** stock the highest score
*/

#include "my.h"

void fill_score(game_t *game, int total_len)
{
    FILE *fd = fopen(".highest_score", "r");
    char *buffer = NULL;
    ssize_t len = 0;
    size_t sz = 0;
    int i = 0;

    game->hscore.highest_score = malloc(total_len + 1);
    while ((len  = getline(&buffer, &sz, fd)) > 0) {
        for (int j = 0; buffer[j] != '\0'; j++, i++)
            game->hscore.highest_score[i] = buffer[j];
    }
    game->hscore.highest_score[total_len] = '\0';
    fclose(fd);
}

void stock_score(game_t *game)
{
    FILE *fd = fopen(".highest_score", "r");
    char *buffer = NULL;
    ssize_t len = 0;
    size_t sz = 0;
    int total_len = 0;

    while ((len  = getline(&buffer, &sz, fd)) > 0)
        total_len += len;
    fclose(fd);
    fill_score(game, total_len);
}

void stock_highest_score(game_t *game)
{
    int fd = open(".highest_score", O_RDWR);

    if (game->score.score > my_atoi(game->hscore.highest_score)) {
        game->hscore.highest_score = my_itoa(game->score.score);
        write(fd, game->hscore.highest_score, int_len(game->score.score));
    }
    close(fd);
}
