/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** window
*/

#include "my.h"

sfRenderWindow *create_mywindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode vd_md = {width, height, 32};

    window = sfRenderWindow_create(vd_md, "MyRunner", sfResize | sfClose, NULL);
    return (window);
}
