#include "printf.h"

size_t	ft_putadrs_directiv(void *adrs, t_directiv *direct)
{
	uintptr_t	address;
	uintptr_t	temp;
	size_t	len_puts;

	len_puts = 0;
	len_puts += 2;
	address = (uintptr_t)adrs;
	temp = address;
	if (address == 0)
		len_puts++;
	while (temp != 0)
	{
		temp = temp / 16;
		len_puts++;
	}
	if (direct->field_width > (int)len_puts && direct->flag_minus == 1)
	{
		ft_putadrs(address);
		ft_putchar_repeat(' ', direct->field_width - len_puts);
		len_puts = direct->field_width;
	}
	else if (direct->field_width > (int)len_puts)
	{
		ft_putchar_repeat(' ', direct->field_width - len_puts);
		ft_putadrs(address);
		len_puts = direct->field_width;
	}
	else
		ft_putadrs(address);
	return (len_puts);
}

// int main()
// {
// 	int n;
// 	t_directiv	direct;

// 	ft_putadrs_directiv(NULL, &direct);
// }