/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:09:21 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:09:26 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned short	ft_count_digits_int(int num)
{
	int	count_digits;

	count_digits = 0;
	if (num == -2147483648)
		return (11);
	else if (num < 0)
	{
		count_digits++;
		num = -num;
	}
	if (num == 0)
		count_digits++;
	while (num)
	{
		count_digits++;
		num = num / 10;
	}
	return (count_digits);
}
