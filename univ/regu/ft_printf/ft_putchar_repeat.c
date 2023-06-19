/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_repeat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:12:56 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:12:58 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_repeat(char c, size_t num_repeat)
{
	size_t	i;

	i = num_repeat;
	while (i--)
	{
		if (write (1, &c, 1) == -1)
			return (-1);
	}
	return (num_repeat);
}
