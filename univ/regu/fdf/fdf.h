#ifndef FDF_H
# define FDF_H

//include
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>

//for test
# include <stdio.h>

//define

//typdef
typedef struct	s_fdf
{
	size_t			axis;
	size_t			ordinate;
	int				altitude;
	unsigned int	color;
	struct s_fdf	*next;
}	t_fdf;

//prototype
t_fdf	*ft_get_map(char *filename, t_fdf **list_d);
char	*get_next_line(int fd);
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *src);
char	*ft_atoi_base(char *str, char *base, char *baseto);
void	ft_lstadd_back(t_fdf **lst, t_fdf *new);

#endif