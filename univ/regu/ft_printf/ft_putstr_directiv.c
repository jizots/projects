/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_directiv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:15:31 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:15:33 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_repeat_str(char ch_repeat, size_t size_repeat, char *str)
{
	ft_putchar_repeat(ch_repeat, size_repeat);
	ft_putstr(str);
	return (size_repeat);
}

size_t	ft_put_str_repeat(char *str, char ch_repeat, size_t size_repeat)
{
	ft_putstr(str);
	ft_putchar_repeat(ch_repeat, size_repeat);
	return (size_repeat);
}

static void	ft_putstr_directiv2(char *str, t_directiv *direct, size_t *len_puts)
{
	if (direct->preci != -1 && (int)*len_puts > direct->preci)
	{
		ft_putchar_repeat(' ', (direct->width - direct->preci));
		ft_putnstr(str, direct->preci);
	}
	else
		ft_put_repeat_str(' ', (direct->width - (int)*len_puts), str);
	*len_puts = direct->width;
}

void	ft_putstr_bigwidth(char *str, t_directiv *direct, size_t *len_puts)
{
	if (direct->preci != -1 && (int)*len_puts > direct->preci)
	{
		ft_putnstr(str, direct->preci);
		ft_putchar_repeat(' ', (direct->width - direct->preci));
	}
	else
		ft_put_str_repeat(str, ' ', (direct->width - *len_puts));
	*len_puts = direct->width;
}

size_t	ft_putstr_directiv(char *str, t_directiv *direct)
{
	size_t	len_puts;
	char	flag_free;

	flag_free = 0;
	if (str == NULL)
	{
		flag_free = 1;
		str = ft_strdup("(null)");
	}
	len_puts = ft_strlen(str);
	if (direct->width > (int)len_puts && direct->flag_minus == 1)
		ft_putstr_bigwidth(str, direct, &len_puts);
	else if (direct->width > (int)len_puts)
		ft_putstr_directiv2(str, direct, &len_puts);
	else if ((int)len_puts > direct->preci && direct->preci != -1)
	{
		ft_putnstr(str, direct->preci);
		len_puts = direct->preci;
	}
	else
		ft_putstr(str);
	if (flag_free == 1)
		free(str);
	return (len_puts);
}
