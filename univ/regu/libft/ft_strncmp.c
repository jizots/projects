/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:07:31 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:07:35 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int main()
// {
// 	char src[]=  "12345678901234567890";
// 	char src2[]= "12345678901234567890";
//     int i = 2; //check i=0 && str[0] is not same

//     if (strncmp(src, src2, i) == ft_strncmp(src, src2, i))
//         puts("success");
//     else
//         puts("fault");
//     return (0);
// }
