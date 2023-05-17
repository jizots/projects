# static lib
LIBNAME	=	ft.a

CC = cc

CFLAGS	=	-Wall -Wextra -Werror

SRCDIR	= src
INCDIR	= includes

SRCS	=	ft_basex.c ft_mathh.c ft_putx.c ft_stringh.c

OBJS	=	$(SRCS:%.c=$(SRCDIR)/%.o)

all:	$(LIBNAME)

$(LIBNAME):	$(OBJS)
	ar rcs $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(LIBNAME)

re:	fclean all
