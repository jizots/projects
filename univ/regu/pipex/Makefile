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
	libft.a\

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
