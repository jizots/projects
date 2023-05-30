/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:03:21 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:14:25 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

// int main()
// {
// 	int c = 0;
//	
// 	for ( ; c<128; c++)
// 	{
// 		if (isprint(c) == ft_isprint(c))
// 			printf ("%c %d %d\n", c, isprint(c), ft_isprint(c));
// 		else
// 		{
// 			puts("faulse");
// 			return (-1);
// 		}
// 	}
// 	puts("ture");
// 	return (0);
// }
