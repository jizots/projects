#include "push_swap.h"

void	ft_delete_datas(t_list *stack)
{
	t_list	*next;

	while (stack->content != NULL)
	{
		next = stack->next;
		free (stack->content);
		free (stack);
		stack = next;
	}
	free (stack);
}