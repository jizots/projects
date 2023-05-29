#include "printf.h"

size_t	ft_putstr_directiv(char *str, t_directiv *direct)
{
	size_t	len_puts;

	len_puts = ft_strlen(str);
	if (direct->field_width > (int)len_puts && direct->flag_minus == 1)
	{
		if (direct->preci != -1 && (int)len_puts > direct->preci)
		{
			ft_putnstr(str, direct->preci);
			ft_putchar_repeat(' ', (direct->field_width - direct->preci));
		}
		else
		{
			ft_putstr(str);
			ft_putchar_repeat(' ', (direct->field_width - len_puts));
		}
		len_puts = direct->field_width;
	}
	else if (direct->field_width > (int)len_puts)
	{
		if (direct->preci != -1 && (int)len_puts > direct->preci)
		{
			ft_putchar_repeat(' ', (direct->field_width - direct->preci));
			ft_putnstr(str, direct->preci);
		}
		else
		{
			ft_putchar_repeat(' ', (direct->field_width - len_puts));
			ft_putstr(str);
		}
		len_puts = direct->field_width;
	}
	else if ((int)len_puts > direct->preci)
	{
		ft_putnstr(str, direct->preci);
		len_puts = direct->preci;
	}
	else
		ft_putstr(str);
	return (len_puts);
}