/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_directiv6.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:14:52 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:14:54 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_directiv6(t_directiv *direct, int *len_puts, char *p_n)
{
	*len_puts += direct->preci - (*len_puts - 1);
	if (*len_puts < direct->width)
		*len_puts += ft_putchar_repeat(' ', direct->width - *len_puts);
	if (direct->flag_plus == 1)
		ft_putchar('+');
	else
		ft_putchar(' ');
	ft_put_repeat_str('0', direct->preci - ft_strlen(p_n), p_n);
}

void	ft_putnbr_directiv3(t_directiv *direct, int *len_puts, char *p_n)
{
	if (direct->flag_zero == 1)
	{
		if (direct->flag_plus == 1)
			ft_putchar('+');
		else
			ft_putchar(' ');
		*len_puts += ft_put_repeat_str('0', direct->width - *len_puts, p_n);
	}
	else
	{
		*len_puts += ft_putchar_repeat(' ', direct->width - *len_puts);
		ft_putchar('+');
		ft_putstr(p_n);
	}
}

void	ft_putnbr_space_plus(t_directiv *direct, int *len_puts, char *p_n)
{
	if (*len_puts < direct->preci)
		ft_putnbr_directiv6(direct, len_puts, p_n);
	else if (++(*len_puts) < direct->width)
		ft_putnbr_directiv3(direct, len_puts, p_n);
	else if (direct->flag_plus == 1)
		ft_put_repeat_str('+', 1, p_n);
	else
		ft_put_repeat_str(' ', 1, p_n);
}
