#ifndef PUSH_SWAP
# define PUSH_SWAP

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
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

//prototype
char	**ft_split(const char *, char);
void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
t_list	*ft_make_initial_stack(char **, t_list *);//Fucn:atoi args, and make list.  Return:error(-1), else(0). 
void	ft_delete_datas(t_list *stack);
int		ft_atoi(const char *src, char **flag_error);
t_list	*ft_add_stack(t_list *stack, int *value);
t_list	*ft_push_swap(t_list *);
int		ft_lstsize(t_list *lst);
t_list	*ft_size_two(t_list *root);
size_t	ft_ascending_sorted(t_list *list);
size_t	ft_descending_sorted(t_list *list);
t_list	*ft_swap_single(t_list *list, char *action);
void	ft_swap_double(t_list *lista, t_list *listb);

#endif