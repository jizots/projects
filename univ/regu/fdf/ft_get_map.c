#include "fdf.h"

t_fdf	*ft_newlist(size_t axis, size_t ordinate, size_t altitude, unsigned int color)
{
	t_fdf	*newlist;

	newlist = malloc (sizeof(t_fdf) * 1);
	if (newlist == NULL)
		return (NULL);
	newlist->axis = axis;
	newlist->ordinate = ordinate;
	newlist->altitude = altitude;
	newlist->color = color;
	newlist->next = NULL;
	return (newlist);
}

t_fdf	**ft_str_conv_data(char *str, t_fdf **list_d, int ordinate, int axis)
{
	t_fdf			*newlist;
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
			if(tmp == NULL)
				return (NULL);
			color = ft_atoi(tmp);
			free(tmp);
			break ;
		}
		else
			i++;
	}
	newlist = ft_newlist(axis, ordinate, ft_atoi(str), color);
	if (newlist == NULL)
		return (NULL);
	ft_lstadd_back(list_d, newlist);//一番最後を探すのにめっちゃ時間かかる気がするので、最後の要素を与えて、そこにサクッと追加するのが良さそう。
	return (list_d);
}

t_fdf	**ft_line_convert_data(char *line, t_fdf **list_d, int ordinate, size_t *size_col)
{
	char	**matrix;
	size_t	axis;
	size_t	i;

	matrix = ft_split(line, ' ');
	if (matrix == NULL)
		return (NULL);//must free list_d
	i = 0;
	if (ordinate == 0)
	{
		*size_col = 0;
		while (matrix[i])
			*size_col = ++i;
	}
	else
	{
		while (matrix[i] != NULL)
			i++;
		if (*size_col != i)
		{
			write(1, "temp mes\n", 9);
			return (NULL);//must put message.
		}
	}
	axis = 0;
	while (matrix[axis] != NULL)
	{
		list_d = ft_str_conv_data(matrix[axis], list_d, ordinate, axis);//must error check
		free(matrix[axis]);
		axis++;
	}
	free(matrix);
	return (list_d);
}

t_fdf	*ft_get_map(char *filename, t_fdf **list_d)
{
	int		fd;
	char	*line;
	size_t	ordinate;
	size_t	size_col;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ordinate = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		list_d = ft_line_convert_data(line, list_d, ordinate, &size_col);
		if (*list_d == NULL)
			return (NULL);
		free(line);
		ordinate++;
	}
	return (*list_d);
}

	//構造体リストの作成がめちゃくちゃ遅い