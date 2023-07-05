NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_get_map.c main.c ft_lstadd_back.c
OBJS = $(SRCS:%.c=%.o)
LIBORFT_DIR = liborft
LIBORFT_STATIC = $(LIBORFT_DIR)/liborft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBORFT_STATIC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBORFT_DIR) -lorft

$(LIBORFT_STATIC):
	$(MAKE) -C $(LIBORFT_DIR)

clean:
	$(MAKE) -C $(LIBORFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBORFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
