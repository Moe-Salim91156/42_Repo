NAME    = unit_test
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I../framework -I../libft

SRC_DIR = strlen
LIBFT_DIR = ../libft

LIBFT_A = $(LIBFT_DIR)/libft.a

SRC     = ../framework/libunit.c \
          main.c \
          $(SRC_DIR)/00_launcher.c \
          $(SRC_DIR)/01_ok_test.c \
          $(SRC_DIR)/02_ko_test.c \
          $(SRC_DIR)/03_segv_test.c \
          $(SRC_DIR)/04_bus_test.c

OBJ     = $(SRC:.c=.o)

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -o $(NAME)

test: all
	./$(NAME)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
