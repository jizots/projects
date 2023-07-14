/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts_dot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:35:01 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/13 17:50:00 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	ft_puts_dot(t_data **map, const size_t x, const size_t y)
// {
	
// }


double	ft_hypotenus_of_pytgrs(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

int	ft_puts_dot_fromto(double from_x, double from_y, double to_x, double to_y)
{
	double	radian;
	double	radius;

	radius = ft_hypotenus_of_pytgrs(to_x - from_x, to_y - from_y);
	radian = atan((to_y - from_y) / (to_x - from_x));
	while (radius >= 0)
	{
		my_mlx_pixel_put(&img, from_x + (radius * cos(radian)), from_y + (radius * sin(radian)), 0x00FF0000);
		radius--;
	}
}