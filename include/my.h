/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** protos
*/

#ifndef MY_
#define MY_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "gameplay.h"
#include "window.h"
#include "music.h"

/* my */
/* lib */

int my_strcmp(char const *s1, char const *s2);
int my_atoi(char const *s1);
char *my_itoa(int nb);
int int_len(int nb);

/* main function */

void ini_all(window_t *dwd, game_t *game, music_t *music);
void events(window_t *dwd, game_t *game, music_t *music);
void in_event(window_t *dwd, music_t *music_t);

/* window */

int my_runner(char *filepath);

/* map */

int stock_map(char *filepath, game_t *game);
void ini_map(game_t *game);
void disp_obs(game_t *game);
void disp_map(game_t *game, window_t *dwd, music_t *music);

/* clock */

void clock_parallax(window_t *dwd);

/* window */

void set_parallax(window_t *dwd);
sfRenderWindow *create_mywindow(unsigned int width, unsigned int height);
void parallax_cond(window_t *dwd);
void parallax(window_t *dwd);
void disp_pause(window_t *dwd, game_t *game, music_t *music);
void set_button_pause(window_t *dwd);

/* menu */

void ini_menu(window_t *dwd, game_t *game, music_t *music);
void set_menu(window_t *dwd);
void cond_menu(window_t *dwd, game_t *game);
void disp_menu(window_t *dwd, game_t *game, music_t *music);
void event_in_menu(window_t *dwd, game_t *game, music_t *music);
void ini_music(music_t *music);

/* history */

void disp_history(window_t *dwd, game_t *game, music_t *music);
void cond_return(game_t *game, window_t *dwd, music_t *music);

/* shop */

void disp_shop(window_t *dwd, game_t *game, music_t *music);
void buy_shop(window_t *dwd);
void set_button_shop(window_t *dwd);
void hit_box_shop(window_t *dwd, game_t *game);
void disp_bought(window_t *dwd);
void load_skin(window_t *dwd, game_t *game);

/* pause */

void cond_resume(game_t *game, window_t *dwd, music_t *music);
void event_in_pause(window_t *dwd);

/* button */

void pos_button(window_t *dwd);
void rect_button(window_t *dwd);
void cond_ini_button(window_t *dwd);
void ini_button(window_t *dwd);
void disp_menu_button(window_t *dwd);
void cond_play(game_t *game, window_t *dwd, music_t *music);
void cond_leave(game_t *game, window_t *dwd);
void cond_history(game_t *game, window_t *dwd, music_t *music);
void cond_shop(game_t *game, window_t *dwd, music_t *music);

/* gameplay */

void set_character(game_t *game);
void display_character(game_t *game, window_t *dwd);
void jump(game_t *game, window_t *dwd);
void ini_hit(game_t *game);
void hit(game_t *game, window_t *dwd, music_t *music);

/* mouse */

void ini_mouse(game_t *game);
void mouse(window_t *dwd, game_t *game);

/* free */

void destroy_more_gameplay(game_t *game);
void destroy_all(window_t *dwd, game_t *game, music_t *music);

/* over */

void ini_over(window_t *dwd);
void disp_over(window_t *dwd, music_t *music, game_t *game);
void cond_over_menu(game_t *game, window_t *dwd, music_t *music);
void ini_over_menu(window_t *dwd, game_t *game);

/* score */

void score(game_t *game);
void score_progress(game_t *game, window_t *dwd);
void hight_score(game_t *game);
void stock_score(game_t *game);
void stock_highest_score(game_t *game);

/* zombie */

void ini_zombie(game_t *game);
void animated_zombie(game_t *game);

#endif
