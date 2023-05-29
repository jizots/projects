#include "printf.h"

size_t	ft_putchar_directiv(char c, t_directiv *direct)
{
	size_t	len_puts;

	len_puts = 0;
	if (direct->field_width > 1 && direct->flag_minus == 1)
	{
		ft_putchar(c);
		len_puts = ft_putchar_repeat(' ', direct->field_width - 1) + 1;
	}
	else if (direct->field_width > 1)
	{
		len_puts = ft_putchar_repeat(' ', direct->field_width - 1) + 1;
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		len_puts++;
	}
	return (len_puts);
}