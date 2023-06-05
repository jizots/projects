/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:09:24 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:09:27 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}

// int main()
// {
//     int c = 0;
//     for ( ; c < 128; c++)
//     {
//         printf("%c %c\n", tolower(c), ft_tolower(c));
//         if (tolower(c) != ft_tolower(c))
//             return (-1);
//     }
//     puts("success");
//     return (0);
// }
