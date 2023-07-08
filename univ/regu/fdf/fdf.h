/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:00:32 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/08 15:01:17 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
typedef struct s_fdf
{
	int				altitude;
	unsigned int	color;
	struct s_fdf	*next;
}	t_fdf;

//prototype
int		ft_free_sprit(char **matrix);
int		ft_free_map(t_fdf **map, const int y);
t_fdf	**ft_get_map(char *filename, int *x, int *y);
int		ft_make_mapbase(char *filename, t_fdf ***map_empty, int *x, int *y);
int		ft_print_perror(char *original_message);
int		ft_mes_error(char *message);
char	*get_first_line(int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ft_count_word(char *str);
char	**ft_split_multichar(const char *s, const char *multichar);
int		ft_atoi(const char *src);
char	*ft_atoi_base(char *str, char *base, char *baseto);

#endif