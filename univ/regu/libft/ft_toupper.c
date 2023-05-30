/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:09:40 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:09:42 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

// int main()
// {
//     int c = 0;
//     for ( ; c < 128; c++)
//     {
//         printf("%c %c\n", toupper(c), ft_toupper(c));
//         if (toupper(c) != ft_toupper(c))
//             return (-1);
//     }
//     puts("success");
//     return (0);
// }
