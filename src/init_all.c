/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** init_all
*/

#include "my.h"

void ini_pos_parallax(window_t *dwd)
{
    dwd->parallax.pos_forest.x = 0;
    dwd->parallax.pos_fog.x = 0;
    dwd->parallax.pos_ground.x = 0;
    dwd->parallax.pos_trees.x = 0;
    dwd->parallax.pos_forest.y = 0;
    dwd->parallax.pos_fog.y = 0;
    dwd->parallax.pos_ground.y = 0;
    dwd->parallax.pos_trees.y = 0;
    sfSprite_setPosition(dwd->parallax.forest_s,
                            dwd->parallax.pos_forest);
    sfSprite_setPosition(dwd->parallax.fog_s,
                            dwd->parallax.pos_fog);
    sfSprite_setPosition(dwd->parallax.ground_s,
                            dwd->parallax.pos_ground);
    sfSprite_setPosition(dwd->parallax.trees_s,
                            dwd->parallax.pos_trees);
    dwd->menu.first_open = 1;
    ini_over(dwd);
}

void ini_variables(window_t *dwd, game_t *game, music_t *music)
{
    dwd->menu.is_open = 1;
    sfMusic_setLoop(music->menu, sfTrue);
    sfMusic_setLoop(music->game, sfTrue);
    sfMusic_play(music->menu);
    sfMusic_setVolume(music->menu, 25);
    sfMusic_setVolume(music->click, 25);
    sfMusic_setVolume(music->game, 10);
    sfMusic_setVolume(music->shoot, 25);
    dwd->menu.shop.in_shop = malloc(2);
    game->chara.jump = 0;
    ini_hit(game);
    set_button_pause(dwd);
    sfMusic_setVolume(music->sword, 17);
    game->obs.speed = 0;
    dwd->over.open_over = 0;
    score(game);
    hight_score(game);
    ini_zombie(game);
    game->score.clock_score = sfClock_create();
    stock_score(game);
}

void ini_all(window_t *dwd, game_t *game, music_t *music)
{
    sfVector2f origin_mouse = {50 / 2, 50 / 2};

    dwd->window = create_mywindow(1920, 1080);
    ini_mouse(game);
    ini_music(music);
    ini_variables(dwd, game, music);
    set_menu(dwd);
    set_parallax(dwd);
    set_character(game);
    ini_button(dwd);
    buy_shop(dwd);
    ini_map(game);
    ini_pos_parallax(dwd);
    game->hit.kill = 0;
    sfRenderWindow_setMouseCursorVisible(dwd->window, sfFalse);
    sfSprite_setOrigin(game->mouse.mouse_s, origin_mouse);
    sfRenderWindow_setFramerateLimit(dwd->window, 120);
}
