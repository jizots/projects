/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:11:18 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:11:20 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_directiv	*ft_initialize_struct(t_directiv *direct)
{
	direct->f_hash = 0;
	direct->flag_zero = 0;
	direct->flag_minus = 0;
	direct->flag_space = 0;
	direct->flag_plus = 0;
	direct->flag_apost = 0;
	direct->flag_widastr = 0;
	direct->flag_precastr = 0;
	direct->width = -1;
	direct->preci = -1;
	ft_bzero(direct->length_modifier, 3);
	direct->conv_spec = '\0';
	direct->flag_wait = 0;
	return (direct);
}

static int	capt_printf_flag(const char *str, t_directiv *direct)
{
	size_t	j;

	j = 1;
	while (str[j] == '#' || str[j] == '0' || str[j] == '-'
		|| str[j] == ' ' || str[j] == '+')
	{
		if (str[j] == '#')
			direct->f_hash = 1;
		else if (str[j] == '0')
			direct->flag_zero = 1;
		else if (str[j] == '-')
			direct->flag_minus = 1;
		else if (str[j] == ' ')
			direct->flag_space = 1;
		else if (str[j] == '+')
			direct->flag_plus = 1;
		j++;
	}
	return (j);
}

static void	capt_preci(const char *str, t_directiv *direct, size_t *j)
{
	direct->preci = ft_atoi(&str[++(*j)]);
	if (direct->preci > 0)
		*j += ft_count_digits_int(direct->preci);
	else if (str[*j] == '*')
	{
		direct->flag_precastr = 1;
		*j += 1;
	}
}

int	ft_capt_directiv(const char *str, t_directiv *direct)
{
	size_t	j;

	j = capt_printf_flag(str, direct);
	if ('0' <= str[j] && str[j] <= '9')
	{
		direct->width = ft_atoi(&str[j]);
		j += ft_count_digits_int(direct->width);
	}
	else if (str[j] == '*')
	{
		direct->flag_widastr = 1;
		j++;
	}
	if (str[j] == '.')
		capt_preci(str, direct, &j);
	if (str[j] == 'c' || str[j] == 's' || str[j] == 'p'
		|| str[j] == 'd' || str[j] == 'i' || str[j] == 'u'
		|| str[j] == 'x' || str[j] == 'X' || str[j] == '%')
		direct->conv_spec = str[j++];
	else
		return (0);
	return (j);
}
