/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:09:55 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/08 15:30:26 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_str_conv_data(char *str, t_fdf **map, int ix, int iy)
{
	char			*tmp;
	unsigned int	color;
	int				i;

	i = 0;
	color = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			tmp = ft_atoi_base(&str[i + 3], "0123456789ABCDEF", "0123456789");
			if (tmp == NULL)
				return (EXIT_FAILURE);
			color = ft_atoi(tmp);
			free(tmp);
			break ;
		}
		else
			i++;
	}
	map[iy][ix].altitude = ft_atoi(str);
	map[iy][ix].color = color;
	return (EXIT_SUCCESS);
}

int	ft_line_convert_data(char *line, t_fdf **map, const int x, const int y)
{
	int		ix;
	char	**matrix;

	matrix = ft_split_multichar(line, " \n");
	if (matrix == NULL)
		return (ft_free_map(map, y));
	ix = 0;
	while (matrix[ix] != NULL)
		ix++;
	if (ix != x)
	{
		ft_free_sprit(matrix);
		return (ft_mes_error("Wrong line existing.\n"));
	}
	ix = 0;
	while (matrix[ix] != NULL)
	{
		if (ft_str_conv_data(matrix[ix], map, ix, y) != EXIT_SUCCESS)
			return (ft_free_sprit(matrix));
		ix++;
	}
	ft_free_sprit(matrix);
	return (EXIT_SUCCESS);
}

int	ft_get_line(int fd, t_fdf **map, const int *x, const int *y)
{
	int		iy;
	char	*line;

	iy = 0;
	while (iy < *y)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_line_convert_data(line, map, (const int) *x, (const int) iy)
			!= EXIT_SUCCESS)
		{
			ft_free_map(map, *y);
			return (EXIT_FAILURE);
		}
		free(line);
		iy++;
	}
	if (iy != *y)
	{
		ft_free_map(map, *y);
		return (ft_mes_error("Wrong line existing.\n"));
	}
	return (EXIT_SUCCESS);
}

t_fdf	**ft_get_map(char *filename, int *x, int *y)
{
	int		fd;
	t_fdf	**map;

	if (ft_make_mapbase(filename, &map, x, y) != 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (ft_get_line(fd, map, (const int *)x, (const int *)y) == EXIT_FAILURE)
		return (NULL);
	close (fd);
	return (map);
}
