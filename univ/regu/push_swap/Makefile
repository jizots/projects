NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SCRC	=	main.c\
	ft_add_stack.c\
	ft_atoi.c\
	ft_checker_sort.c\
	ft_exec_push.c\
	ft_exec_rotate.c\
	ft_exec_rotate_repeat.c\
	ft_exec_swap.c\
	ft_make_initial_list.c\
	ft_push_swap.c\
	ft_push_swap_utils.c\
	ft_size_under_three.c\
	ft_size_over_six.c\
	ft_size_five.c\
	ft_size_four.c\
	ft_split.c\
	ft_strlib.c\

OBJS	=	$(SCRC:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all