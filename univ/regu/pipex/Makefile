NAME    =   pipex
CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror

SRCS    =   ft_init_data.c\
            ft_fork_for_infile.c\
            ft_fork_for_outfile.c\
            ft_fork_for_repeat.c\
            ft_fork_util.c\
            ft_free.c\
            ft_get_absolute_path.c\
            ft_print_error.c\
            ft_seach_envpaths.c\

MAIN = main.c
BSRCS = ft_heredoc.c
BONUS_MAIN = main_b.c

OBJS    =   $(addprefix obj/, $(SRCS:.c=.o))
MAIN_OBJ = $(addprefix obj/, $(MAIN:.c=.o))
BONUS_MAIN_OBJ = $(addprefix obj/, $(BONUS_MAIN:.c=.o))
BONUS_OBJS = $(addprefix obj/, $(BSRCS:.c=.o))

LIBFT_DIR   = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT_STATIC = $(LIBFT_DIR)/libft.a

GNL_DIR = get_next_line
GNL_MAKEFILE = $(GNL_DIR)/Makefile
GNL_STATIC = $(GNL_DIR)/libgnlft.a

.PHONY: all bonus clean fclean re

all: $(NAME)

bonus: $(GNL_STATIC) $(NAME) 

$(NAME): $(OBJS) $(LIBFT_STATIC) $(if $(findstring $(MAKECMDGOALS), bonus), $(BONUS_OBJS) $(BONUS_MAIN_OBJ), $(MAIN_OBJ))
	$(CC) $(CFLAGS) -o $(NAME) $^ -L$(LIBFT_DIR) -lft $(if $(findstring $(MAKECMDGOALS), bonus), -L$(GNL_DIR) -lgnlft)

obj/%.o: %.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_STATIC):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL_STATIC):
	$(MAKE) -C $(GNL_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -rf obj

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME)

re:	fclean all
