/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:03:49 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:21:40 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int main()
// {
//     char    str[]= ":(){ :|: & };:1234567890qwertyuiop";
//     int     c = '\xde';
//     int     not = 'm';
//     int     num = 12;
//     int     cn = 0;
//     printf ("std %s\nmy  %s\n\n", 
//     	memchr(str, c, 10), ft_memchr(str, c, 10));
//     printf ("std %s\nmy  %s\n\n", 
//     	memchr(str, c, 15), ft_memchr(str, c, 15));
//     printf ("std %s\nmy  %s\n\n", 
//     	memchr(str, not, 30), ft_memchr(str, not, 30));
//     printf ("std %d\nmy  %d\n\n", 
//     	(int)memchr(&num, cn, 4), (int)ft_memchr(&num, cn, 4));
//     return (0);
// }
