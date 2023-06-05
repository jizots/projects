/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:12:55 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:13:06 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}

// int main()
// {
// 	int c = 0;	
// 	for ( ; c<128; c++)
// 	{
// 		if (isalpha(c) == ft_isalpha(c))
// 			printf ("%c %d %d\n", c, isalpha(c), ft_isalpha(c));
// 		else
// 		{
// 			puts("faulse");
// 			return (-1);
// 		}
// 	}
// 	puts("ture");
// 	return (0);
// }
