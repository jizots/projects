/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:06:46 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:06:52 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while ((i < (size - 1)) && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	size_t			i;

	str = (unsigned char *) s;
	c1 = (unsigned char) c;
	if (n == 0 || s == NULL)
		return (NULL);
	i = 0;
	while (i < n && str[i] != c1)
		i++;
	if (i == n)
		return (NULL);
	else
		return ((void *) &str[i]);
}
