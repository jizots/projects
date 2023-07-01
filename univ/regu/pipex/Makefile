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

MAIN	=	main.c
BONUS_MAIN = main_b.c
BSRCS   =   ft_heredoc.c\

ifeq ($(MAKECMDGOALS),bonus)
    MAIN = $(BONUS_MAIN)
    SRCS += $(BSRCS)
endif

SRCS += $(MAIN)
OBJS    =   $(SRCS:%.c=obj/%.o)

LIBFT_DIR   = libft
LIBFT_STATIC = $(LIBFT_DIR)/libft.a

GNL_DIR = get_next_line
GNL_STATIC = $(GNL_DIR)/libgnlft.a

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_STATIC) $(GNL_STATIC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnlft

bonus: $(NAME)

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
