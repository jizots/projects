/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liborft.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:49:33 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/05 16:11:09 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBORFT_H
# define LIBORFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif
//for func
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

//for verify
# include <stdio.h>

//define

//struct

//prototype
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_createline_nobuf(char **s_save, char **s_new, char *flag);
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *src);
char	*ft_atoi_base(char *str, char *base, char *baseto);

#endif
