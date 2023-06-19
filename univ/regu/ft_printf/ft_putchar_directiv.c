/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_directiv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:12:48 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:12:49 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_directiv(char c, t_directiv *direct)
{
	size_t	len_puts;

	len_puts = 0;
	if (direct->width > 1 && direct->flag_minus == 1)
	{
		ft_putchar(c);
		len_puts = ft_putchar_repeat(' ', direct->width - 1) + 1;
	}
	else if (direct->width > 1)
	{
		len_puts = ft_putchar_repeat(' ', direct->width - 1) + 1;
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		len_puts++;
	}
	return (len_puts);
}
