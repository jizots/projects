/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utobase_directiv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:11:45 by sotanaka          #+#    #+#             */
/*   Updated: 2023/05/31 16:11:50 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_utobase_directiv(unsigned long n, t_directiv *direct)
{
	size_t	len_puts;
	char	*p_str;

	p_str = NULL;
	if (direct->conv_spec == 'u')
		p_str = ft_utobase(n, "0123456789");
	else if (direct->conv_spec == 'x')
		p_str = ft_utobase(n, "0123456789abcdef");
	else if (direct->conv_spec == 'X')
		p_str = ft_utobase(n, "0123456789ABCDEF");
	len_puts = ft_strlen(p_str);
	len_puts += ft_puts_utobase(direct, len_puts, p_str);
	free(p_str);
	return (len_puts);
}
