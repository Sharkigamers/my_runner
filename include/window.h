/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** window struct
*/

#ifndef WIND_
#define WIND_

#include "my.h"

typedef struct sec_button
{
    sfTexture *return_t;
    sfSprite *return_s;
    sfVector2f pos_return;
    sfIntRect rect_return;
} sec_button_t;

typedef struct button
{
    sfTexture *play_t;
    sfSprite *play_s;
    sfVector2f pos_play;
    sfIntRect rect_play;
    sfTexture *shop_t;
    sfSprite *shop_s;
    sfVector2f pos_shop;
    sfIntRect rect_shop;
    sfTexture *history_t;
    sfSprite *history_s;
    sfVector2f pos_history;
    sfIntRect rect_history;
    sfTexture *leave_t;
    sfSprite *leave_s;
    sfVector2f pos_leave;
    sfIntRect rect_leave;
    sfTexture *menu_t;
    sfSprite *menu_s;
    sfVector2f pos_menu;
    sfIntRect rect_menu;
} button_t;

typedef struct shop
{
    int is_active;
    char *in_shop;
    sfTexture *shop_t;
    sfSprite *shop_s;
    sfTexture *wood_t;
    sfSprite *wood_s;
    sfVector2f pos_wood;
    sfIntRect rect_wood;
    sfTexture *diam_t;
    sfSprite *diam_s;
    sfVector2f pos_diam;
    sfIntRect rect_diam;
} shop_t;

typedef struct menu
{
    int first_open;
    shop_t shop;
    int is_open;
    sfTexture *menu_t;
    sfSprite *menu_s;
    sfTexture *story_t;
    sfSprite *story_s;
    button_t button;
    sec_button_t sec_button;
    sfTexture *pause_t;
    sfSprite *pause_s;
} menu_t;

typedef struct parallax
{
    sfVector2f pos_ground;
    sfVector2f pos_trees;
    sfVector2f pos_forest;
    sfVector2f pos_sky;
    sfVector2f pos_fog;
    sfClock *clock_paral;
    sfTime time_paral;
    float sec_paral;
    sfTexture *ground_t;
    sfSprite *ground_s;
    sfTexture *trees_t;
    sfSprite *trees_s;
    sfTexture *forest_t;
    sfSprite *forest_s;
    sfTexture *sky_t;
    sfSprite *sky_s;
    sfTexture *fog_t;
    sfSprite *fog_s;
} paral_t;

typedef struct over
{
    int open_over;
    sfTexture *tover_t;
    sfSprite *tover_s;
    sfTexture *szover_t;
    sfSprite *szover_s;
    sfTexture *zover_t;
    sfSprite *zover_s;
    sfTexture *victory_t;
    sfSprite *victory_s;
} over_t;

typedef struct my_window
{
    sfRenderWindow *window;
    sfEvent event;
    over_t over;
    paral_t parallax;
    menu_t menu;
} window_t;

#endif
