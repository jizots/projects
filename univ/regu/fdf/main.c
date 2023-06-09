/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:42:02 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/10 18:40:29 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	**map;
	size_t	xsize;
	size_t	ysize;

	if (ac != 2)
		write(1, "Entry like './fdf filepath'\n", 28);
	else
	{
		map = ft_get_map(av[1], &xsize, &ysize);
		if (map != NULL)
		{
			ft_puts_dot(map, (const size_t)xsize, (const size_t)ysize);
			ft_free_map(map, ysize);
		}
	}
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q fdf");
}