NAME	=	push_swap

BNAME	=	checker

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

BSCRS	=	ft_add_stack_b.c\
	ft_atoi_b.c\
	ft_checker_sort_b.c\
	ft_exec_push_b.c\
	ft_exec_rotate_b.c\
	ft_exec_swap_b.c\
	ft_get_next_line.c\
	ft_get_next_line_utils.c\
	ft_main_b.c\
	ft_make_initial_list_b.c\
	ft_push_swap_b.c\
	ft_split.c\
	ft_strlib_b.c\
	ft_strstr.c\

OBJS	=	$(SCRC:%.c=%.o)
BOBJS	=	$(BSCRS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:	$(BOBJS)
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean:	clean
	rm -f $(NAME) $(BNAME)

re:	fclean all