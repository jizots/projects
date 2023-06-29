NAME	=	pipex
BNAME	=	pipex

CC		=	cc -g

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	main.c\
	ft_init_data.c\
	ft_fork_for_infile.c\
	ft_fork_for_outfile.c\
	ft_fork_for_repeat.c\
	ft_fork_util.c\
	ft_free.c\
	ft_get_absolute_path.c\
	ft_print_error.c\
	ft_seach_envpaths.c\

BSRCS	=	test.c\
	ft_init_data.c\
	ft_fork_for_infile.c\
	ft_fork_for_outfile.c\
	ft_fork_for_repeat.c\
	ft_fork_util.c\
	ft_free.c\
	ft_get_absolute_path.c\
	ft_print_error.c\
	ft_seach_envpaths.c\

OBJS	=	$(SRCS:%.c=%.o)
BOBJS	=	$(BSRCS:%.c=%.o)

LIBFT_DIR = Libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT_STATIC = $(LIBFT_DIR)/libft.a

GNL_DIR = get_next_line
GNL_MAKEFILE = $(GNL_DIR)/Makefile
GNL_STATIC = $(GNL_DIR)/libgnlft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_STATIC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

bonus:	$(BOBJS) $(LIBFT_STATIC) $(GNL_STATIC)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS) -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnlft

$(LIBFT_STATIC):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL_STATIC):
	$(MAKE) -C $(GNL_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME)
	rm -f $(BNAME)
	
re:	fclean all
