#include "push_swap.h"

int	ft_lstsize(t_list *list)
{
	int	value_return;

	if (list == NULL)
		return (0);
	value_return = 0;
	while (list->content != NULL)
	{
		list = list->next;
		value_return++;
		if (value_return < 0)
			return (-1);
	}
	return (value_return);
}