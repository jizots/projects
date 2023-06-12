#include "push_swap.h"

t_list	*ft_create_list(void *content, t_list *prev, t_list *next)
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