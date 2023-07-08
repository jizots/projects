/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:42:02 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/08 15:36:20 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_free_map(t_fdf **map, const int y)
{
	int	iy;

	iy = 0;
	while (iy < y)
	{
		free(map[iy]);
		iy++;
	}
	free(map);
	return (EXIT_FAILURE);
}

int	ft_free_sprit(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i++]);
	}
	free(matrix);
	return (EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fdf	**map;
	int		xsize;
	int		ysize;

	if (ac != 2)
		write(1, "Entry like './fdf filepath'\n", 28);
	else
	{
		map = ft_get_map(av[1], &xsize, &ysize);
int x = 0;
int y = 0;
while(y < ysize)
{
x = 0;
while (x < xsize)
{
printf("alti:%d  color:%u\n", map[y][x].altitude, map[y][x].color);
x++;
}
y++;
}
	}
system("leaks -q fdf");
	return (0);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q fdf");
}