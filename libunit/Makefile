CC          := cc
CFLAGS      := -Wall -Wextra -Werror -Ilibft -Iframework

LIBFT_DIR   := libft
LIBUNIT_DIR := framework

LIBFT_LIB   := $(LIBFT_DIR)/libft.a
LIBUNIT_LIB := $(LIBUNIT_DIR)/libunit.a

REAL_EXEC   := real_tests_exec

SRC_MAIN    := main.c
OBJ_MAIN    := $(SRC_MAIN:.c=.o)

SRC_REAL    := real-tests/00_launcher.c real-tests/01_basic_test.c real-tests/02_empty_file.c \
	       real-tests/03_strcpy_basic.c real-tests/04_strcpy_empty.c \
	       real-tests/05_ft_strncmp_equal.c real-tests/06_ft_strncmp_different.c \
	       real-tests/07_ft_atoi_basic.c real-tests/08_ft_atoi_negative.c real-tests/09_ft_atoi_invalid.c \
	       real-tests/10_ft_memset_basic.c real-tests/11_ft_memset_zero_len.c \
	       real-tests/12_ft_strdup_basic.c real-tests/13_ft_strdup_empty.c \
	       real-tests/14_ft_isalpha_basic.c real-tests/15_ft_bzero_basic.c real-tests/16_ft_bzero_zero_len.c

OBJ_REAL    := $(SRC_REAL:.c=.o)

.PHONY: all real_tests dummy_tests clean fclean re

all: real_tests dummy_tests

real_tests: $(LIBFT_LIB) $(LIBUNIT_LIB) $(OBJ_MAIN) $(OBJ_REAL)
	@echo "Building real_tests..."
	$(CC) $(CFLAGS) -o $(REAL_EXEC) $(OBJ_MAIN) $(OBJ_REAL) $(LIBUNIT_LIB) $(LIBFT_LIB)

dummy_tests:
	@echo "Running dummy_tests..."
	$(MAKE) -C tests

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(LIBUNIT_LIB):
	$(MAKE) -C $(LIBUNIT_DIR)

clean:
	rm -f $(OBJ_MAIN) $(OBJ_REAL)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(LIBUNIT_DIR) clean
	$(MAKE) -C tests clean

fclean: clean
	rm -f $(REAL_EXEC)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(LIBUNIT_DIR) fclean
	$(MAKE) -C tests fclean

re: fclean all

