#include "push_swap.h"

void	ft_push(t_list **from, t_list **to, char *action)
{
	t_list	*tmp_prev;
	t_list	*tmp_next;

	tmp_prev = (*from)->prev;
	tmp_next = (*from)->next;
	(*to)->prev->next = *from;
	(*from)->prev = (*to)->prev;
	(*from)->next = *to;
	(*to)->prev = *from;
	tmp_prev->next = tmp_next;
	tmp_next->prev = tmp_prev;
	*to = *from;
	*from = tmp_next;
	write(1, action, 2);
	write(1, "\n", 1);

for(t_list *tmp = *from; tmp->cont != NULL; tmp = tmp->next)
{
printf("from->%d\n", *(tmp->cont));
}
for(t_list *tmp = *to; tmp->cont != NULL; tmp = tmp->next)
{
printf("to->%d\n", *(tmp->cont));
}
}