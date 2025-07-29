NAME    = libunit.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC     = libunit.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
