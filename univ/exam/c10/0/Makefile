TARGET	=	ft_display_file

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	c100.c

OBJS	=	$(SRCS:%.c=%.o)

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all