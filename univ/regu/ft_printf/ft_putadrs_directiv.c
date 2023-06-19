/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs_directiv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:12:17 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:12:21 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putadrs_directiv(void *adrs, t_directiv *direct)
{
	size_t		len_puts;
	char		*p_hex;

	p_hex = ft_utobase((unsigned long)adrs, "0123456789abcdef");
	len_puts = ft_strlen(p_hex) + 2;
	if (direct->width > (int)len_puts && direct->flag_minus == 1)
	{
		ft_putadrs(p_hex);
		ft_putchar_repeat(' ', direct->width - len_puts);
		len_puts = direct->width;
	}
	else if (direct->width > (int)len_puts)
	{
		ft_putchar_repeat(' ', direct->width - len_puts);
		ft_putadrs(p_hex);
		len_puts = direct->width;
	}
	else
		ft_putadrs(p_hex);
	free(p_hex);
	return (len_puts);
}

// int main()
// {
// 	int n;
// 	t_directiv	direct;

// 	ft_putadrs_directiv(NULL, &direct);
// }
