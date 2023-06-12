/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:01:46 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/19 18:01:52 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_len_isspace3(const char *src)
{
	size_t	len;

	len = 0;
	while (src[len] == ' ' || src[len] == '\f' || src[len] == '\n'
		|| src[len] == '\r' || src[len] == '\t' || src[len] == '\v')
		len++;
	return (len);
}

static signed char	ft_isminus(const char *src, size_t *i)
{
	if (src[*i] == '-')
	{
		*i += 1;
		return (-1);
	}
	else if (src[*i] == '+')
		*i += 1;
	return (0);
}

int	ft_atoi(const char *src, char **flag_error)
{
	size_t			i;
	unsigned int	result;
	signed char		sign_flag;

	i = ft_len_isspace3(src);
	sign_flag = ft_isminus(src, &i);
	result = 0;
	while (src[i] && ('0' <= src[i] && src[i] <= '9'))
	{
		if (sign_flag == 0 && ((INT_MAX / 10) <= result
					&& ('8' <= src[i] && src[i] <= '9')))
			*flag_error = NULL;
		if (sign_flag == -1 && (INT_MAX / 10) <= result && '9' == src[i])
			*flag_error = NULL;
		result = result * 10 + (src[i] - '0');
		i++;
	}
	if (src[i] != '\0' && (src[i] < '0' || '9' < src[i]))
		*flag_error = NULL;
	if (sign_flag == -1)
		return (-result);
	return (result);
}

// int main(void)
// {
//     char    str[] = "  0.1";
// 	char	*flag;

// 	flag = str;
//     if (printf("%d\n", ft_atoi(str, &flag)) && flag != NULL)
//         puts("success");
//     else
//         puts("fault");
// 	return (0);
// }
