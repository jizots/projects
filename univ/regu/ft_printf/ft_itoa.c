/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:03:37 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:15:30 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_input(int n, char *dest, unsigned int digit_int)
{
	dest[digit_int] = '\0';
	if (n == INT_MIN)
		ft_strcpy(dest, "-2147483648");
	else if (n == 0)
		ft_strcpy(dest, "0");
	else
	{
		if (n < 0)
		{
			ft_strcpy(&dest[0], "-");
			n = -n;
		}
		while (n != 0)
		{
			dest[digit_int - 1] = (n % 10) + '0';
			n = n / 10;
			digit_int--;
		}
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	unsigned int	digit_int;
	char			*str_int;

	digit_int = ft_count_digits_int(n);
	str_int = ft_calloc (digit_int + 1, sizeof(char));
	if (str_int == NULL)
		return (NULL);
	return (ft_itoa_input(n, str_int, digit_int));
}

// int main()
// {
// printf("0:%s -2147483:%s -2147483648:%s 2147483647:%s", 
// 	ft_itoa(0), ft_itoa(-2147483), ft_itoa(-2147483648), ft_itoa(2147483647));
// }
