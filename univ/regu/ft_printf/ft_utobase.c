/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:11:36 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:11:38 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	input_hexadecimal(unsigned long n, char *base, char *p_result,
unsigned char len_result)
{
	unsigned char	len_base;
	int				i;

	len_base = (unsigned char)ft_strlen(base);
	i = 0;
	if (n == 0)
		p_result[0] = '0';
	while (n != 0)
	{
		p_result[len_result - 1 - i] = base[n % len_base];
		n = n / len_base;
		i++;
	}
}

char	*ft_utobase(unsigned long n, char *base)
{
	unsigned char	len_base;
	unsigned char	len_result;
	char			*p_result;
	unsigned long	temp_n;

	if (base == NULL || base[0] == '\0' || ft_str_only_chr(base) == -1)
	{
		write(1, "base error", 10);
		return (NULL);
	}
	temp_n = n;
	len_base = (unsigned char)ft_strlen(base);
	len_result = 0;
	while (temp_n != 0)
	{
		temp_n = temp_n / len_base;
		len_result++;
	}
	if (n == 0)
		len_result = 1;
	p_result = ft_calloc(sizeof(char), (len_result + 1));
	if (p_result == NULL)
		return (NULL);
	input_hexadecimal(n, base, p_result, len_result);
	return (p_result);
}

// int main()
// {
//     char    base[]="0123456789";
//     unsigned long     nbr = 0;
// 	char *p;

// 	p = ft_utobase(nbr, "0123456789");
//     printf ("my   %s\n", p);
// 	free(p);

//     printf ("std  %lx\n", nbr);

// 	p = ft_utobase(140732748421192, "0123456789abcdef");
//     printf ("myx  %s\n", p);
// 	free(p);

// 	p = ft_utobase(nbr, "0123456789ABCDEF");
//     printf ("myX  %s\n", p);
// 	free(p);
//     return (0);
// }
