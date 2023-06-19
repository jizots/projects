/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:30:42 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:30:44 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr(const char *str, size_t n)
{
	if (str == NULL)
		return (-1);
	while (n-- != 0 && *str != '\0')
	{
		if (write(1, str++, 1) == -1)
			return (-1);
	}
	return (0);
}
