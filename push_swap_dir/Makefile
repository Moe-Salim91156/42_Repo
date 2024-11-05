CC = cc 

CFLAGS = -Wall -Wextra -Werror

PWSRCS = push_swap.c algo_refactor.c pop.c reverse_rotate.c rotate.c sorted.c swap.c push.c empty.c sort_three.c sort_five.c sort_four.c Algo.c

PWOBJ = $(PWSRCS:.c=.o)

LIBFT_DIR = ../libft

OBJ_DIR = obj

LIBFT_A = ../libft/libft.a

NAME = push_swap



all: $(LIBFT_A) $(NAME)

$(NAME) : $(PWOBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR) -lft

$(LIBFT_A) : 
	make -C $(LIBFT_DIR)
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(PWOBJ)

fclean : clean
	$(MAKE) fclean -C  $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
