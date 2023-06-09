/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:55:07 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:55:09 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int		ft_put_error(t_list *root);
char	**ft_split(const char *s, char c);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	ft_delete_datas(t_list *stack);
int		ft_atoi(const char *src, char **flag_error);
t_list	*ft_make_initial_stack(char **args);
t_list	*ft_add_stack(t_list *stack, int *value);
t_list	*ft_push_swap(t_list *sta);
int		ft_lstsize(t_list *lst);
size_t	ft_locate_minimum(t_list *root);
size_t	ft_locate_maximum(t_list *root);
size_t	ft_locate_specify(t_list *list, int specify);
int		*ft_sort_int(t_list *list);
t_list	*ft_size_two_a(t_list *root);
t_list	*ft_size_two_b(t_list *root);
t_list	*ft_size_three_a(t_list *sta);
t_list	*ft_size_three_b(t_list *stb);
t_list	*ft_size_four_a(t_list *sta, t_list *stb);
t_list	*ft_size_four_b(t_list *stb, t_list *sta);
t_list	*ft_size_five_a(t_list *sta, t_list *stb);
t_list	*ft_size_five_b(t_list *sta, t_list *stb);
t_list	*ft_size_over_six(t_list *sta, t_list *stb, size_t size_lst);
int		ft_inta_is_small(int *a, int *b);
int		ft_intb_is_small(int *a, int *b);
size_t	ft_ascending_sorted(t_list *list);
size_t	ft_descending_sorted(t_list *list);
t_list	*ft_swap_single(t_list *list, char *action);
void	ft_swap_double(t_list **lista, t_list **listb);
void	ft_simple_swap(t_list **sta, t_list **stb, int flag);
t_list	*ft_rotate(t_list *list, char *action);
t_list	*ft_r_rotate(t_list *list, char *action);
t_list	*ft_rotate_repeat(t_list *st, char *action, char *r_action, size_t nor);
void	ft_push(t_list **from, t_list **to, char *action);

#endif