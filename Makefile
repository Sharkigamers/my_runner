##
## EPITECH PROJECT, 2018
## my_runner
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/my_runner.c	\
		src/stock_map.c	\
		src/window.c	\
		src/init_all.c	\
		src/init_button.c	\
		src/menu_button.c	\
		src/menu_button_second.c	\
		src/annex_button.c	\
		src/history.c	\
		src/shop.c	\
		src/annex_shop.c	\
		src/parallax.c	\
		src/main_event.c	\
		src/charcter.c	\
		src/event_character.c	\
		src/menu.c	\
		src/mouse.c	\
		src/music.c	\
		src/destroy.c	\
		src/pause.c	\
		src/annex_pause.c	\
		src/annex_menu.c	\
		src/hit.c	\
		src/map.c	\
		src/game_over.c	\
		src/over_event.c	\
		src/annex_over.c	\
		src/score.c	\
		src/stock_score.c	\
		src/zombie.c	\
		src/annex_destroy.c	\

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/my -lmy

CSFML	=	-lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-graphics

CPPFLAGS	=	-I./include/ -Wall -Wextra

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(SRC) $(CSFML) $(LIB) $(CPPFLAGS)

clean:
	cd lib/my && make clean
	rm -f $(OBJ)
	cd src/ && rm -f $(OBJ)

fclean: clean
	cd lib/my && make fclean
	rm -f $(NAME)
	cd src/ && rm -f $(OBJ)

re:	fclean all

.PHONY: all clean fclean re
