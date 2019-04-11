/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** gameplay
*/

#ifndef GAME_
#define GAME_

#include "my.h"

typedef struct hight_score
{
    char *highest_score;
    long hscore;
    sfText *hscore_t;
    sfFont *hscore_f;
    sfVector2f pos_hscore;
    sfText *htext_t;
    sfFont *htext_f;
    sfVector2f pos_htext;
} hscore_t;

typedef struct score
{
    sfClock *clock_score;
    sfTime time_score;
    float sec_score;
    long score;
    sfText *score_t;
    sfFont *score_f;
    sfVector2f pos_score;
    sfText *text_t;
    sfFont *text_f;
    sfVector2f pos_text;
} score_t;

typedef struct mouse
{
    sfVector2i mouse_pos;
    sfVector2f pos;
    sfTexture *mouse_t;
    sfSprite *mouse_s;
} mouse_t;

typedef struct character
{
    sfClock *clock_jump;
    sfTime time_jump;
    float sec_jump;
    int jump;
    sfClock *clock_chara;
    sfTime time_chara;
    float sec_chara;
    sfTexture *champ_t;
    sfSprite *champ_s;
    sfVector2f pos_champ;
    sfIntRect rect_champ;
} chara_t;

typedef struct hit
{
    int kill;
    int nb_hit;
    int is_click;
    sfSprite *hit_s;
    sfTexture *hit_t;
    sfVector2f pos_hit;
    sfIntRect rect_hit;
} hit_t;

typedef struct obstacle
{
    sfClock *clock_obs;
    sfTime time_obs;
    float sec_obs;
    sfTexture *peak_t;
    sfSprite *peak_s;
    sfVector2f pos_peak;
    sfIntRect rect_peak;
    long speed;
    sfTexture *zombie_t;
    sfSprite *zombie_s;
    sfVector2f pos_zombie;
    sfIntRect rect_zombie;
    sfTexture *house_t;
    sfSprite *house_s;
    sfVector2f pos_house;
    sfIntRect rect_house;
} obs_t;

typedef struct gameplay
{
    char *map;
    char *save_map;
    score_t score;
    hscore_t hscore;
    obs_t obs;
    hit_t hit;
    mouse_t mouse;
    chara_t chara;
} game_t;

#endif
