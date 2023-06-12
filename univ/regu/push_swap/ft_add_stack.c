#include "push_swap.h"

static t_list	*ft_create_stack(void *content, t_list *prev, t_list *next)
{
	t_list	*new;

	new = malloc (sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->prev = prev;
	new->next = next;
	return (new);
}

static t_list	*ft_add_effective_stack(t_list *stack, int *value)
{
	t_list	*last;
	t_list	*new;

	last = stack;
	while (last->next->content != NULL)
		last = last->next;
	new = ft_create_stack((void *) value, last, last->next);
	if (new == NULL)
	{
		ft_delete_datas(stack);
		return (NULL);
	}
	last->next = new;
	new->next->prev = new;
	return (stack);
}

t_list	*ft_add_stack(t_list *stack, int *value)
{
	t_list	*sentinel;

	if (stack == NULL)
	{
		sentinel = ft_create_stack(NULL, NULL, NULL);
		if (sentinel == NULL)
			return (NULL);
		stack = ft_create_stack((void *) value, sentinel, sentinel);
		if (stack == NULL)
		{
			ft_delete_datas(sentinel);
			free(value);
			return (NULL);
		}
		sentinel->prev = stack;
		sentinel->next = stack;
		return (stack);
	}
	stack = ft_add_effective_stack(stack, value);
	return (stack);
}