GNL_NAME = libgnlft.a

GNL_SRCS = get_next_line.c get_next_line_utils.c

GNL_OBJS = $(GNL_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(GNL_NAME)

$(GNL_NAME): $(GNL_OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(GNL_OBJS)

fclean: clean
	rm -f $(GNL_NAME)

re: fclean all
