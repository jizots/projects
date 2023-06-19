NAME	=	libftprintf.a
CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror
SCRS	=	ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_count_digits_int.c\
	ft_itoa.c\
	ft_memset.c\
	ft_printf.c\
	ft_printf_2.c\
	ft_putadrs.c\
	ft_putadrs_directiv.c\
	ft_putchar.c\
	ft_putchar_directiv.c\
	ft_putchar_repeat.c\
	ft_putnbr_directiv.c\
	ft_putnbr_directiv6.c\
	ft_putnbr_int.c\
	ft_putnstr.c\
	ft_putstr.c\
	ft_putstr_directiv.c\
	ft_put_utobase.c\
	ft_strcpy.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_toupper.c\
	ft_utobase.c\
	ft_utobase_directiv.c\
	ft_str_only_chr.c\

BSCRS	=	ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_count_digits_int.c\
	ft_itoa.c\
	ft_memset.c\
	ft_printf.c\
	ft_printf_2.c\
	ft_putadrs.c\
	ft_putadrs_directiv.c\
	ft_putchar.c\
	ft_putchar_directiv.c\
	ft_putchar_repeat.c\
	ft_putnbr_directiv.c\
	ft_putnbr_directiv6.c\
	ft_putnbr_int.c\
	ft_putnstr.c\
	ft_putstr.c\
	ft_putstr_directiv.c\
	ft_put_utobase.c\
	ft_strcpy.c\
	ft_strdup.c\
	ft_strlen.c\
	ft_toupper.c\
	ft_utobase.c\
	ft_utobase_directiv.c\
	ft_str_only_chr.c\

OBJS	=	$(SCRS:%.c=%.o)
BOBJS	=	$(BSCRS:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $@ $^

bonus:	$(OBJS) $(BOBJS)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJS) $(BOBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all