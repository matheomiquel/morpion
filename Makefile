CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -std=c99

NAME    = morpion
RM      = rm -f
SRC	= \
	my_putchar.c \
    my_putstr.c \
	main.c \
	my_strcat.c \
	my_strlen.c \
	my_putnbr.c \
	my_strcmp.c \
	brain.c \
	my_getnbr.c \

OBJ     = $(SRC:.c=.o)

all:
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re