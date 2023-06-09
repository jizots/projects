/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:10:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/13 17:52:18 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_hypotenus_of_pytgrs(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

double	ft_leg_of_rest(double hypotenus, double leg)
{
	return (sqrt(pow(hypotenus, 2) - pow(leg, 2)));
}

double	ft_expand_dot_interval(double window_max, double xsize)
{
	double	tmp;
	double	expanded;

	tmp = sqrt(3) * xsize;
	expanded = (window_max / 2) / tmp;
	return (expanded);
}

// int main()
// {
// 	double	x;
// 	double	y;

// 	printf("expanded: %f\n", ft_expand_dot_interval(100, 50));
// }