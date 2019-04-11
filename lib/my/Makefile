##
## EPITECH PROJECT, 2018
## my_runner
## File description:
## Makefile for lib
##

SRC	=	my_strcmp.c	\
		atoi.c	\
		itoa.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
