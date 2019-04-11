/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** shop of the game
*/

#include "my.h"

void buy_shop(window_t *dwd)
{
    int fd = open(".shop", O_RDONLY);

    read(fd, dwd->menu.shop.in_shop, 1);
    dwd->menu.shop.in_shop[1] = '\0';
    dwd->menu.shop.is_active = my_atoi(dwd->menu.shop.in_shop);
    close(fd);
    free(dwd->menu.shop.in_shop);
    set_button_shop(dwd);
    sfSprite_setTextureRect(dwd->menu.shop.wood_s, dwd->menu.shop.rect_wood);
    sfSprite_setPosition(dwd->menu.shop.wood_s, dwd->menu.shop.pos_wood);
    sfSprite_setTextureRect(dwd->menu.shop.diam_s, dwd->menu.shop.rect_diam);
    sfSprite_setPosition(dwd->menu.shop.diam_s, dwd->menu.shop.pos_diam);
    disp_bought(dwd);
}

void set_button_shop(window_t *dwd)
{
    dwd->menu.shop.pos_wood.x = 50;
    dwd->menu.shop.pos_wood.y = 50;
    dwd->menu.shop.pos_diam.x = 550;
    dwd->menu.shop.pos_diam.y = 50;
    dwd->menu.shop.rect_wood.left = 22;
    dwd->menu.shop.rect_wood.top = 10;
    dwd->menu.shop.rect_wood.height = 476;
    dwd->menu.shop.rect_wood.width = 476;
    dwd->menu.shop.rect_diam.left = 500;
    dwd->menu.shop.rect_diam.top = 10;
    dwd->menu.shop.rect_diam.height = 480;
    dwd->menu.shop.rect_diam.width = 476;
    dwd->menu.shop.wood_t = sfTexture_createFromFile
        ("assets/menu/shop_obj.png", NULL);
    dwd->menu.shop.wood_s = sfSprite_create();
    sfSprite_setTexture(dwd->menu.shop.wood_s, dwd->menu.shop.wood_t, sfTrue);
    dwd->menu.shop.diam_t = sfTexture_createFromFile
        ("assets/menu/shop_obj.png", NULL);
    dwd->menu.shop.diam_s = sfSprite_create();
    sfSprite_setTexture(dwd->menu.shop.diam_s, dwd->menu.shop.diam_t, sfTrue);
}

void event_in_shop(window_t *dwd)
{
    if (dwd->event.type == sfEvtClosed) {
        sfRenderWindow_close(dwd->window);
        dwd->menu.is_open = 0;
    }
}

void disp_shop(window_t *dwd, game_t *game, music_t *music)
{
    while (dwd->menu.is_open == 4) {
        cond_return(game, dwd, music);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.shop.shop_s, NULL);
        sfRenderWindow_drawSprite
            (dwd->window, dwd->menu.sec_button.return_s, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.shop.wood_s, NULL);
        sfRenderWindow_drawSprite(dwd->window, dwd->menu.shop.diam_s, NULL);
        if (sfRenderWindow_pollEvent(dwd->window, &dwd->event)) {
            event_in_shop(dwd);
            hit_box_shop(dwd, game);
        }
        mouse(dwd, game);
        sfRenderWindow_display(dwd->window);
    }
}
