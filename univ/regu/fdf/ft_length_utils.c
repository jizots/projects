/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:10:08 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/08 15:10:52 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_hypotenus_of_pytgrs(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

// int main()
// {
// 	double	x;
// 	double	y;

// 	printf("hepotenus of x & y: %f\n", ft_hypotenus_of_pytgrs(sqrt(3),1));
// }