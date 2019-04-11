/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** menu for the runner
*/

#include "my.h"

void mouse_on(game_t *game, window_t *dwd, music_t *music)
{
    cond_play(game, dwd, music);
    cond_shop(game, dwd, music);
    cond_history(game, dwd, music);
    cond_leave(game, dwd);
}

void set_menu(window_t *dwd)
{
    dwd->menu.menu_t = sfTexture_createFromFile("assets/menu/menu.jpg", NULL);
    dwd->menu.menu_s = sfSprite_create();
    sfSprite_setTexture(dwd->menu.menu_s, dwd->menu.menu_t, sfTrue);
    dwd->menu.story_t = sfTexture_createFromFile("assets/menu/story.jpg", NULL);
    dwd->menu.story_s = sfSprite_create();
    sfSprite_setTexture(dwd->menu.story_s, dwd->menu.story_t, sfTrue);
    dwd->menu.shop.shop_t = sfTexture_createFromFile
        ("assets/menu/shop.jpg", NULL);
    dwd->menu.shop.shop_s = sfSprite_create();
    sfSprite_setTexture(dwd->menu.shop.shop_s, dwd->menu.shop.shop_t, sfTrue);
}

void cond_menu(window_t *dwd, game_t *game)
{
    sfRenderWindow_drawSprite(dwd->window, dwd->menu.menu_s, NULL);
    disp_menu_button(dwd);
    sfRenderWindow_drawText(dwd->window, game->hscore.htext_t, NULL);
    sfText_setString
        (game->hscore.hscore_t, game->hscore.highest_score);
    sfRenderWindow_drawText(dwd->window, game->hscore.hscore_t, NULL);
}

void event_in_menu(window_t *dwd, game_t *game, music_t *music)
{
    if (dwd->event.type == sfEvtClosed) {
        sfRenderWindow_close(dwd->window);
        dwd->menu.is_open = 0;
    }
    mouse_on(game, dwd, music);
}

void disp_menu(window_t *dwd, game_t *game, music_t *music)
{
    while (dwd->menu.is_open == 1) {
        ini_menu(dwd, game, music);
        cond_menu(dwd, game);
        mouse(dwd, game);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            event_in_menu(dwd, game, music);
        }
        sfRenderWindow_display(dwd->window);
        disp_history(dwd, game, music);
        disp_shop(dwd, game, music);
    }
}
