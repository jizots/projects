#include "printf.h"

size_t	ft_putp_nbr_directiv(int n, t_directiv *direct)
{
	size_t	len_puts;
	char	*p_nbr;

	len_puts = 0;
	p_nbr = ft_itoa(n);
	len_puts = ft_strlen(p_nbr);
	if (direct->flag_plus == 1 && n > 0)
	{
		if ((len_puts + 1) < direct->field_width)
		{
			if (direct->flag_minus == 1)
			{

			}
			else if (direct->flag_zero == 1)
			{

			}
			else if 
		}

	}
	else if (len_puts < direct->field_width)
	{

	}
	else
	{

	}
	free(p_nbr);
	return (len_puts);
}