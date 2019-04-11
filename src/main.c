/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    int fd = open("READ_ME", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 374);
    char *save_buffer = buffer;

    if (env == NULL)
        return (84);
    if (ac < 1 || ac > 2)
        return (84);
    if (ac == 2 && av[1][0] != '-') {
        if (my_runner(av[1]) == 84)
            return (84);
    }
    else if (ac == 2 && (my_strcmp(av[0], "./my_runner") == 0) &&
            (my_strcmp(av[1], "-h") == 0)) {
        read(fd, buffer, 373);
        write(1, buffer, 373);
    }
    free(save_buffer);
    close(fd);
    return (0);
}
