/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_only_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:16:13 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:31:15 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_only_chr(char *str)
{
	size_t	len_str;
	size_t	start;
	size_t	i;

	len_str = ft_strlen(str);
	start = 0;
	while (str[start] != '\0')
	{
		i = start + 1;
		while (str[i] != '\0')
		{
			if (str[start] == str[i])
				return (-1);
			i++;
		}
		start++;
	}
	return (0);
}

// int main()
// {
// 	printf ("%d", ft_str_only_chr("asdfghjklqwaertyuio"));
// }
