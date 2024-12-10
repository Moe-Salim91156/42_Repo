CC = cc 

CFLAGS = -Wall -Wextra -Werror -g
MFLAGS = -L minilibx-linux -lmlx -lXext -lX11
LIBFT_DIR = libft

SRCS_DIR = srcs
OBJS_DIR = objs

LIBFT_A = $(LIBFT_DIR)/libft.a

INCLUDE = includes

src = start.c map_parser.c load_images.c player_actions.c
SRCS = $(addprefix $(SRCS_DIR)/, $(src)) #prefix (prepend the / for the dir name
OBJS = $(addprefix $(OBJS_DIR)/, $(src:.c=.o)) # same thing here 

NAME = so_long


all : $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJS) $(LIBFT_A) $(MFLAGS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR) #( "|" means only if it exits , ensuring it exists (order))
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@

$(OBJS_DIR): #( if it doesnt create it)
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean : clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re : fclean all

.PHONY: fclean all clean re 
