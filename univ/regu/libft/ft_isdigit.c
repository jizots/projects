/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:03:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:14:00 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

// int main()
// {
// 	int c = 0;
//	
// 	for ( ; c<128; c++)
// 	{
// 		if (isdigit(c) == ft_isdigit(c))
// 			printf ("%c %d %d\n", c, isdigit(c), ft_isdigit(c));
// 		else
// 		{
// 			puts("faulse");
// 			return (-1);
// 		}
// 	}
// 	puts("ture");
// 	return (0);
// }
