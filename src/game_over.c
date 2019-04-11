/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** game_over
*/

#include "my.h"

void ini_over(window_t *dwd)
{
    dwd->over.tover_t = sfTexture_createFromFile
        ("assets/menu/trap_death.jpg", NULL);
    dwd->over.szover_t = sfTexture_createFromFile
        ("assets/menu/go_die.jpg", NULL);
    dwd->over.zover_t = sfTexture_createFromFile
        ("assets/menu/final_death.jpg", NULL);
    dwd->over.victory_t = sfTexture_createFromFile
        ("assets/menu/victory.jpg", NULL);
    dwd->over.tover_s = sfSprite_create();
    dwd->over.szover_s = sfSprite_create();
    dwd->over.zover_s = sfSprite_create();
    dwd->over.victory_s = sfSprite_create();
    sfSprite_setTexture(dwd->over.tover_s, dwd->over.tover_t, sfTrue);
    sfSprite_setTexture(dwd->over.szover_s, dwd->over.szover_t, sfTrue);
    sfSprite_setTexture(dwd->over.zover_s, dwd->over.zover_t, sfTrue);
    sfSprite_setTexture(dwd->over.victory_s, dwd->over.victory_t, sfTrue);
}

void over_event(window_t *dwd, music_t *music)
{
    if (dwd->event.type == sfEvtKeyPressed) {
        if (dwd->event.key.code == sfKeySpace) {
            dwd->over.open_over = 2;
            sfMusic_play(music->shoot);
        }
    }
    if (dwd->event.type == sfEvtClosed) {
        sfRenderWindow_close(dwd->window);
        dwd->over.open_over = 0;
    }
}

void disp_suicide(window_t *dwd, game_t *game, music_t *music)
{
    while (dwd->over.open_over == 1) {
        sfRenderWindow_drawSprite(dwd->window, dwd->over.szover_s, NULL);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            over_event(dwd, music);
        }
        mouse(dwd, game);
        sfRenderWindow_display(dwd->window);
    }
}

void event_in_over_menu(window_t *dwd)
{
    if (dwd->event.type == sfEvtClosed) {
        sfRenderWindow_close(dwd->window);
        dwd->over.open_over = 0;
    }
}

void disp_over(window_t *dwd, music_t *music, game_t *game)
{
    disp_suicide(dwd, game, music);
    while (dwd->over.open_over >= 2) {
        ini_over_menu(dwd, game);
        if (dwd->over.open_over == 2)
            sfRenderWindow_drawSprite(dwd->window, dwd->over.zover_s, NULL);
        if (dwd->over.open_over == 3)
            sfRenderWindow_drawSprite(dwd->window, dwd->over.tover_s, NULL);
        if (dwd->over.open_over == 4)
            sfRenderWindow_drawSprite(dwd->window, dwd->over.victory_s, NULL);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
        event_in_over_menu(dwd);
        cond_over_menu(game, dwd, music);
        }
        sfRenderWindow_drawText(dwd->window, game->score.text_t, NULL);
        sfRenderWindow_drawText(dwd->window, game->score.score_t, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.button.menu_s, NULL);
        mouse(dwd, game);
        sfRenderWindow_display(dwd->window);
    }
}
