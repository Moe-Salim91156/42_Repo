CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g

src_dir = srcs
obj_dir = objs

INCLUDE = includes

src = debug.c free.c monitor.c init.c philo.c thread.c states.c states_utils.c

SRCS = $(addprefix $(src_dir)/, $(src))
OBJS = $(addprefix $(obj_dir)/, $(src:.c=.o))

NAME = philo

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJS) -o $@

$(obj_dir)/%.o : $(src_dir)/%.c | $(obj_dir)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

$(obj_dir):
	mkdir -p $(obj_dir)

clean :
	@rm -rf $(obj_dir)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
