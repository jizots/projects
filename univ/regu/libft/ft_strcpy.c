/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:05:44 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:30:28 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*origin;

	origin = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (origin);
}

// int main()
// {
//     char    str1[]="10293jfoefjo";
//     char    str2[30];

//    	printf("%s\n",ft_strcpy(str2, str1));
//    	printf("%s\n",strcpy(str2, str1));
// }
