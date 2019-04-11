/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** inni buttons
*/

#include "my.h"

void pos_button(window_t *dwd)
{
    dwd->menu.button.pos_play.x = 1000;
    dwd->menu.button.pos_play.y = 150;
    dwd->menu.button.pos_shop.x = 1000;
    dwd->menu.button.pos_shop.y = 350;
    dwd->menu.button.pos_history.x = 1000;
    dwd->menu.button.pos_history.y = 550;
    dwd->menu.button.pos_leave.x = 1000;
    dwd->menu.button.pos_leave.y = 750;
    dwd->menu.button.pos_menu.x = 650;
    dwd->menu.button.pos_menu.y = 500;
    sfSprite_setTextureRect
        (dwd->menu.button.play_s, dwd->menu.button.rect_play);
    sfSprite_setTextureRect
        (dwd->menu.button.shop_s, dwd->menu.button.rect_shop);
    sfSprite_setTextureRect
        (dwd->menu.button.history_s, dwd->menu.button.rect_history);
    sfSprite_setTextureRect
        (dwd->menu.button.leave_s, dwd->menu.button.rect_leave);
    sfSprite_setTextureRect
        (dwd->menu.button.menu_s, dwd->menu.button.rect_menu);
}

void rect_button(window_t *dwd)
{
    dwd->menu.button.rect_play.left = 0;
    dwd->menu.button.rect_play.top = 0;
    dwd->menu.button.rect_play.height = 168;
    dwd->menu.button.rect_play.width = 522;
    dwd->menu.button.rect_shop.left = 0;
    dwd->menu.button.rect_shop.top = 0;
    dwd->menu.button.rect_shop.height = 168;
    dwd->menu.button.rect_shop.width = 530;
    dwd->menu.button.rect_history.left = 0;
    dwd->menu.button.rect_history.top = 0;
    dwd->menu.button.rect_history.height = 168;
    dwd->menu.button.rect_history.width = 530;
    dwd->menu.button.rect_leave.left = 0;
    dwd->menu.button.rect_leave.top = 0;
    dwd->menu.button.rect_leave.height = 168;
    dwd->menu.button.rect_leave.width = 530;
    dwd->menu.button.rect_menu.left = 566;
    dwd->menu.button.rect_menu.top = 368;
    dwd->menu.button.rect_menu.height = 168;
    dwd->menu.button.rect_menu.width = 545;
}

void cond_ini_button(window_t *dwd)
{
    sfSprite_setTexture
        (dwd->menu.button.play_s, dwd->menu.button.play_t, sfTrue);
    sfSprite_setTexture
        (dwd->menu.button.shop_s, dwd->menu.button.shop_t, sfTrue);
    sfSprite_setTexture
        (dwd->menu.button.history_s, dwd->menu.button.history_t, sfTrue);
    sfSprite_setTexture
        (dwd->menu.button.leave_s, dwd->menu.button.leave_t, sfTrue);
    sfSprite_setTexture
        (dwd->menu.button.menu_s, dwd->menu.button.menu_t, sfTrue);
    rect_button(dwd);
    pos_button(dwd);
    sfSprite_setPosition(dwd->menu.button.play_s,dwd->menu.button.pos_play);
    sfSprite_setPosition(dwd->menu.button.shop_s,dwd->menu.button.pos_shop);
    sfSprite_setPosition
        (dwd->menu.button.history_s,dwd->menu.button.pos_history);
    sfSprite_setPosition(dwd->menu.button.leave_s,dwd->menu.button.pos_leave);
    sfSprite_setPosition(dwd->menu.button.menu_s,dwd->menu.button.pos_menu);
}

void cond_button_return(window_t *dwd)
{
    sfSprite_setTexture
        (dwd->menu.sec_button.return_s, dwd->menu.sec_button.return_t, sfTrue);
    dwd->menu.sec_button.rect_return.left = 0;
    dwd->menu.sec_button.rect_return.top = 0;
    dwd->menu.sec_button.rect_return.height = 168;
    dwd->menu.sec_button.rect_return.width = 522;
    dwd->menu.sec_button.pos_return.x = 1200;
    dwd->menu.sec_button.pos_return.y = 800;
    sfSprite_setTextureRect
        (dwd->menu.sec_button.return_s, dwd->menu.sec_button.rect_return);
    sfSprite_setPosition
        (dwd->menu.sec_button.return_s,dwd->menu.sec_button.pos_return);
}

void ini_button(window_t *dwd)
{
    dwd->menu.button.play_t = sfTexture_createFromFile
        ("assets/menu/button.png", NULL);
    dwd->menu.button.shop_t = sfTexture_createFromFile
        ("assets/menu/button.png", NULL);
    dwd->menu.button.history_t = sfTexture_createFromFile
        ("assets/menu/button.png", NULL);
    dwd->menu.button.leave_t = sfTexture_createFromFile
        ("assets/menu/button.png", NULL);
    dwd->menu.button.menu_t = sfTexture_createFromFile
        ("assets/menu/button.png", NULL);
    dwd->menu.sec_button.return_t = sfTexture_createFromFile
        ("assets/menu/button.png", NULL);
    dwd->menu.button.play_s = sfSprite_create();
    dwd->menu.button.shop_s = sfSprite_create();
    dwd->menu.button.history_s = sfSprite_create();
    dwd->menu.button.leave_s = sfSprite_create();
    dwd->menu.button.menu_s = sfSprite_create();
    dwd->menu.sec_button.return_s = sfSprite_create();
    cond_button_return(dwd);
    cond_ini_button(dwd);
}
