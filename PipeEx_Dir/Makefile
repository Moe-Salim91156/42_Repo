CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ../libft

LIBFT_A = $(LIBFT_DIR)/libft.a

PIPE_SRCS= pipex.c redirect.c free.c find_cmd.c

PIPE_OBJS= $(PIPE_SRCS:.c=.o)

NAME = pipex

all: $(LIBFT_A) $(NAME)

$(NAME) : $(PIPE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

$(LIBFT_A):
	make -C $(LIBFT_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(PIPE_OBJS)

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re : fclean all

.PHONY: all fclean clean re
