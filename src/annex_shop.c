/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** annex_shop
*/

#include "my.h"

void load_skin(window_t *dwd, game_t *game)
{
    if (dwd->menu.shop.is_active == 0)
        game->chara.rect_champ.top = 260;
    if (dwd->menu.shop.is_active == 4)
        game->chara.rect_champ.top = 10;
}

void hit_box_shop(window_t *dwd, game_t *game)
{
    if (game->mouse.mouse_pos.x > 65 && game->mouse.mouse_pos.x < 500 &&
        game->mouse.mouse_pos.y > 56 && game->mouse.mouse_pos.y < 510 &&
        dwd->event.type == sfEvtMouseButtonPressed) {
        dwd->menu.shop.is_active = 0;
        disp_bought(dwd);
    }
    if (game->mouse.mouse_pos.x > 565 && game->mouse.mouse_pos.x < 1000 &&
        game->mouse.mouse_pos.y > 56 && game->mouse.mouse_pos.y < 510 &&
        dwd->event.type == sfEvtMouseButtonPressed) {
        dwd->menu.shop.is_active = 4;
        disp_bought(dwd);
    }
}

void disp_bought(window_t *dwd)
{
    int fd = open(".shop", O_WRONLY);

    if (dwd->menu.shop.is_active == 0) {
        dwd->menu.shop.rect_wood.top = 510;
        dwd->menu.shop.rect_diam.top = 10;
        write(fd, my_itoa(dwd->menu.shop.is_active), 1);
    }
    if (dwd->menu.shop.is_active == 4) {
        dwd->menu.shop.rect_diam.top = 510;
        dwd->menu.shop.rect_wood.top = 10;
        write(fd, my_itoa(dwd->menu.shop.is_active), 1);
    }
    sfSprite_setTextureRect(dwd->menu.shop.wood_s, dwd->menu.shop.rect_wood);
    sfSprite_setTextureRect(dwd->menu.shop.diam_s, dwd->menu.shop.rect_diam);
}
