/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_directiv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:14:30 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:30:25 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_directiv5(t_directiv *direct, int *len_puts, char *p_n)
{
	if ((*len_puts - 1) < direct->preci)
	{
		*len_puts += direct->preci - (*len_puts - 1);
		if (*len_puts < direct->width)
		{
			*len_puts += ft_putchar_repeat(' ', direct->width - *len_puts);
		}
		ft_putchar('-');
		ft_put_repeat_str('0', direct->preci - ft_strlen(p_n) + 1, &p_n[1]);
	}
	else if (*len_puts < direct->width)
	{
		if (direct->flag_zero == 1)
		{
			ft_putchar('-');
			*len_puts += ft_put_repeat_str('0', direct->width - *len_puts,
					&p_n[1]);
		}
		else
		*len_puts += ft_put_repeat_str(' ', direct->width - *len_puts, p_n);
	}
	else
		ft_putstr(p_n);
}

static void	ft_putnbr_directiv4(t_directiv *direct, int *len_puts, char *p_n)
{
	if (*len_puts < direct->preci)
	{
		*len_puts += direct->preci - *len_puts;
		if (*len_puts < direct->width)
			*len_puts += ft_putchar_repeat(' ', direct->width - *len_puts);
		ft_put_repeat_str('0', direct->preci - ft_strlen(p_n), p_n);
	}
	else if (*len_puts < direct->width)
	{
		if (direct->flag_zero == 1)
			*len_puts += ft_put_repeat_str('0', direct->width - *len_puts, p_n);
		else
			*len_puts += ft_put_repeat_str(' ', direct->width - *len_puts, p_n);
	}
	else
		ft_putstr(p_n);
}

static void	ft_putnbr_directiv2(int n,
	t_directiv *direct, int *len_puts, char *p_n)
{
	if (direct->flag_plus == 1 && 0 <= n)
	{
		ft_putchar('+');
		*len_puts += 1;
	}
	else if (direct->flag_space == 1 && 0 <= n)
	{
		ft_putchar(' ');
		*len_puts += 1;
	}
	if (*len_puts < direct->preci && n < 0)
	{
		ft_putchar('-');
		*len_puts += ft_put_repeat_str('0', (direct->preci - *len_puts),
				&p_n[1]);
	}
	else if (*len_puts < direct->preci)
			*len_puts += ft_put_repeat_str('0',
				(direct->preci - (*len_puts - 1)), p_n);
	else if (*len_puts < direct->width)
		*len_puts += ft_put_str_repeat(p_n, ' ', (direct->width - *len_puts));
	else
		ft_putstr(p_n);
}

size_t	ft_putnbr_directiv(int n, t_directiv *direct)
{
	int		len_puts;
	char	*p_n;

	p_n = ft_itoa(n);
	len_puts = ft_strlen(p_n);
	if (direct->flag_minus == 1)
		ft_putnbr_directiv2(n, direct, &len_puts, p_n);
	else
	{
		if ((direct->flag_plus == 1 || direct->flag_space == 1) && 0 <= n)
			ft_putnbr_space_plus(direct, &len_puts, p_n);
		else if (0 <= n)
			ft_putnbr_directiv4(direct, &len_puts, p_n);
		else
			ft_putnbr_directiv5(direct, &len_puts, p_n);
	}
	free(p_n);
	return (len_puts);
}
