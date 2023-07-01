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

BSRCS   =   main_b.c\
		ft_heredoc.c\

OBJS    =   $(SRCS:%.c=obj/%.o)
BOBJS   =   $(BSRCS:%.c=obj_bonus/%.o)

LIBFT_DIR   = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT_STATIC = $(LIBFT_DIR)/libft.a

GNL_DIR = get_next_line
GNL_MAKEFILE = $(GNL_DIR)/Makefile
GNL_STATIC = $(GNL_DIR)/libgnlft.a

.PHONY: all $(NAME) bonus clean fclean re

all: $(NAME)

bonus: $(OBJS) $(BOBJS) $(LIBFT_STATIC) $(GNL_STATIC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(BOBJS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnlft

$(NAME): obj/main.o $(OBJS) $(LIBFT_STATIC)
	$(CC) $(CFLAGS) -o $(NAME) obj/main.o $(OBJS) -L$(LIBFT_DIR) -lft

obj/%.o: %.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

obj_bonus/%.o: %.c
	mkdir -p obj_bonus
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_STATIC):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL_STATIC):
	$(MAKE) -C $(GNL_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -rf obj obj_bonus

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME)

re:	fclean all