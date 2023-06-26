NAME	=	pipex

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c\
	ft_fork_for_infile.c\
	ft_fork_for_outfile.c\
	ft_fork_for_repeat.c\
	ft_fork_util.c\
	ft_free.c\
	ft_get_absolute_path.c\
	ft_print_error.c\
	ft_seach_envpaths.c\

OBJS	=	$(SRCS:%.c=%.o)

LIBFT_DIR = Libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT_STATIC = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_STATIC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT_STATIC):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	
re:	fclean all
