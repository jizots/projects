NAME	=	liborft.a
CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SCRS	=	get_next_line.c	get_next_line_utils.c \
	ft_atoi.c ft_split.c ft_strlcpy.c ft_atoi_base.c\

OBJS	=	$(SCRS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all