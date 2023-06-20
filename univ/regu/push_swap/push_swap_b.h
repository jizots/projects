/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:55:07 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:55:09 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_B_H
# define PUSH_SWAP_B_H
# define BUFFER_SIZE 100

//include header
# include <stdlib.h> // for malloc
# include <errno.h> // for malloc
# include <limits.h> //for atoi
# include <unistd.h> //for write

//for verify
# include <stdio.h>

//typdef
typedef struct s_list
{
	int				*cont;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

//prototype
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_createline_nobuf(char **save, char **s_nl, char *flag);
char	*ft_free_memory(char *mem1, char *mem2);
char	*ft_get_next_line(void);
char	*ft_strstr(const char *haystack, const char *needle);
size_t	ft_ascending_sorted(t_list *list);
t_list	*ft_add_stack(t_list *stack, int *value);
int		ft_atoi(const char *src, char **flag_error);
void	ft_delete_datas(t_list *stack);
int		ft_put_error(t_list *root);
t_list	*ft_make_initial_stack(char **args);
char	**ft_split(const char *s, char c);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
void	b_push(t_list **from, t_list **to);
t_list	*b_swap_single(t_list *list);
void	b_swap_double(t_list **lista, t_list **listb);
t_list	*b_rotate(t_list *list);
t_list	*b_r_rotate(t_list *list);
void	b_rotate_double(t_list **sta, t_list **stb);
void	b_r_rotate_double(t_list **sta, t_list **stb);
int		ft_lstsize(t_list *list);
t_list	*b_push_swap(t_list *sta);

#endif