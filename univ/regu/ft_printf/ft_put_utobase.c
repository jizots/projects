/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utobase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:19:00 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:23:08 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print0x_is_need(t_directiv *direct, char *p_str)
{
	if (p_str[0] == '0')
		return ;
	if (direct->f_hash == 1 && direct->conv_spec == 'x')
		ft_putstr("0x");
	else if (direct->f_hash == 1 && direct->conv_spec == 'X')
		ft_putstr("0X");
}

static void	ft_puts_utobase_fminus(t_directiv *direct,
	size_t *len_opt, size_t len_puts, char *p_str)
{
	if (p_str[0] != '0' && direct->f_hash == 1
		&& (direct->conv_spec == 'x' || direct->conv_spec == 'X'))
	{
		print0x_is_need(direct, p_str);
		*len_opt += 2;
	}
	if ((int)len_puts < direct->preci)
		*len_opt += ft_put_repeat_str('0', (direct->preci - len_puts), p_str);
	else
		ft_putstr(p_str);
	if ((int)(len_puts + *len_opt) < direct->width)
		*len_opt += ft_putchar_repeat(' ',
				(direct->width - (len_puts + *len_opt)));
}

static void	ft_puts_utobase_prec_width(t_directiv *direct,
	size_t *len_opt, size_t len_puts, char *p_str)
{
	if (direct->preci < (int)len_puts)
	{
		*len_opt += ft_putchar_repeat(' ',
				(direct->width - (len_puts + *len_opt)));
		print0x_is_need(direct, p_str);
	}
	else if (direct->preci > (int)len_puts)
	{
		*len_opt += ft_putchar_repeat(' ',
				(direct->width - (len_puts + *len_opt)));
		print0x_is_need(direct, p_str);
		ft_putchar_repeat('0', (direct->preci - len_puts));
	}
}

static void	ft_puts_utobase_bigwidth(t_directiv *direct,
	size_t *len_opt, size_t len_puts, char *p_str)
{
	if (direct->flag_zero == 1 && direct->preci == -1)
	{
		if (direct->f_hash == 1)
		{
			print0x_is_need(direct, p_str);
			*len_opt += ft_putchar_repeat('0',
					(direct->width - (len_puts + *len_opt)));
		}
		else
			*len_opt += ft_putchar_repeat('0',
					(direct->width - (len_puts + *len_opt)));
	}
	else if (direct->preci != -1)
		ft_puts_utobase_prec_width(direct, len_opt, len_puts, p_str);
	else
	{
		*len_opt += ft_putchar_repeat(' ',
				direct->width - (len_puts + *len_opt));
		print0x_is_need(direct, p_str);
	}
}

size_t	ft_puts_utobase(t_directiv *direct, size_t len_puts, char *p_str)
{
	size_t	len_opt;

	len_opt = 0;
	if (direct->flag_minus == 1)
		ft_puts_utobase_fminus(direct, &len_opt, len_puts, p_str);
	else if (direct->flag_minus == 0)
	{
		if (p_str[0] != '0' && direct->f_hash == 1
			&& (direct->conv_spec == 'x' || direct->conv_spec == 'X'))
			len_opt += 2;
		if ((int)len_puts < direct->preci)
			len_opt += direct->preci - len_puts;
		if ((int)(len_puts + len_opt) < direct->width)
			ft_puts_utobase_bigwidth(direct, &len_opt, len_puts, p_str);
		else
		{
			print0x_is_need(direct, p_str);
			if (direct->preci > (int)len_puts)
				ft_putchar_repeat('0', (direct->preci - len_puts));
		}
		ft_putstr(p_str);
	}
	return (len_opt);
}
