NAME	=	libft.a
CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SCRS	=	get_next_line.c	get_next_line_utils.c \

OBJS	=	$(SCRS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all