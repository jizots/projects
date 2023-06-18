#include "push_swap.h"

t_list	*ft_rotate_repeat(t_list *st, char *action, char *r_action, size_t nor)
{
	size_t	size_stack;

	if (st == NULL || st->cont==NULL || action == NULL || nor == 0)
		return (st);
	size_stack = ft_lstsize(st);
	if ((size_stack / 2) > nor)
	{
		while (nor-- > 0)
			st = ft_rotate(st, action);
	}
	else
	{
		while ((size_stack - nor++) > 0)
			st = ft_r_rotate(st, r_action);
	}
	return (st);
}
