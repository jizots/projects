NAME	=	push_swap
CC		=	cc
CFLAGS	=	#-Wall -Wextra -Werror
SCRC	=	main.c\
	ft_exec_push.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_delete_datas.c\
	ft_push_swap.c\
	ft_checker_sort.c\
	ft_exec_rotate.c\
	ft_split.c\
	ft_add_stack.c\
	ft_memchr.c\
	ft_exec_swap.c\
	ft_size_two.c\
	ft_make_initial_list.c\
	ft_atoi.c\
	ft_push_swap_utils.c\

OBJS	=	$(SCRC:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all