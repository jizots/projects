/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:42:50 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/08 15:24:51 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liborft.h"

size_t	ft_strlen_base(char *s, char *base)
{
	size_t	i;
	size_t	count;

	i = 0;
	if (s == NULL || base == NULL)
		return (0);
	count = 0;
	while(s[i])
	{
		while (ft_strchr(base, s[i]) == NULL)
			break ;
		count++;
		i++;
	}
	return (count);
}

int	power_lenbase(int lenbase, int power)
{
	int	result;

	result = 1;
	if (!power)
		return (1);
	while (power--)
	{
		result = lenbase * result;
	}
	return (result);
}

int	search_basenum(char c, char *base, int lenbase)
{
	int	i;

	i = 0;
	while (base[i] != c)
	{	
		if (i == lenbase)
			return (-1);
		i++;
	}
	return (i);
}

void	input_array(int decimal, char *result, int hexlen, size_t reslen)
{
	char	c;

	if (decimal >= hexlen)
	{
		input_array(decimal / hexlen, result, hexlen, reslen - 1);
	}
	c = (decimal % hexlen) + '0';
	result[reslen - 1] = c;
}

char	*ft_input_baseto(int decimal, char *baseto, char *result)
{
	int		hexlen;
	size_t	reslen;
	int		temp_decimal;

	hexlen = ft_strlen(baseto);
	reslen = 0;
	temp_decimal = decimal;
	while (temp_decimal != 0)
	{
		reslen++;
		temp_decimal = temp_decimal / hexlen;
	}
	result = malloc(sizeof(char) * (reslen + 2));
	if (result == NULL)
		return (NULL);
	if (decimal < 0)
		;
	else
	{
		result[reslen] = '\0';
		input_array(decimal, result, hexlen, reslen);
	}
	return (result);
}

char	*ft_atoi_base(char *str, char *base, char *baseto)
{
	int		lenstr;
	int		lenbase;
	int		decimal;
	int		power;
	char	*result;

	result = NULL;
	lenstr = ft_strlen_base(str, base);
	lenbase = ft_strlen(base);
	power = 0;
	decimal = 0;
	while (power < lenstr)
	{
		decimal += power_lenbase(lenbase, power)
			* search_basenum(str[lenstr - 1 - power], base, lenbase);
		power++;
	}
	result = ft_input_baseto(decimal, baseto, result);
	return (result);
}
