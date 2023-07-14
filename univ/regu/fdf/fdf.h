/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:00:32 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/11 16:10:49 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*    include    */
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>

/*    for test    */
# include <stdio.h>

/*    define    */

/*    typdef    */
typedef struct s_fdf
{
	int				altitude;
	unsigned int	color;
	struct s_fdf	*next;
}	t_fdf;

/*    prototype    */
//ft_get_map
t_fdf	**ft_get_map(char *filename, int *x, int *y);
//ft_free_allocate
int		ft_free_sprit(char **matrix);
int		ft_free_map(t_fdf **map, const int y);
//ft_make_mapbase
int		ft_make_mapbase(char *filename, t_fdf ***map_empty, int *x, int *y);
//ft_print_error
int		ft_print_perror(char *original_message);
int		ft_mes_error(char *message);
//liborft
char	*get_first_line(int fd);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	ft_count_word(char *str);
char	**ft_split_multichar(const char *s, const char *multichar);
int		ft_atoi(const char *src);
char	*ft_atoi_base(char *str, char *base, char *baseto);

//ft_length_utils
double	ft_hypotenus_of_pytgrs(double x, double y);
double	ft_xypoint_of_45deg(double radius);
double	ft_leg_of_rest(double hypotenus, double leg);
double	ft_expand_dot_interval(double window_max, double xsize);

//ft_puts_dot
// int		ft_puts_dot(t_data **map, const size_t x, const size_t y);

#endif