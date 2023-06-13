#include "push_swap.h"

t_list	*ft_push(t_list *from, t_list *to, char *action)//befor verify
{
	t_list	*tmp_prev;
	t_list	*tmp_next;

	tmp_prev = from->prev;
	tmp_next = from->next;
	to->prev->next = from;
	from->prev = to->prev;
	from->next = to;
	to->prev = from;
	tmp_prev->next = tmp_next;
	tmp_next->prev = tmp_prev;
	write(1, action, 2);
	write(1, '\n', 1);
	return (from);//please change root node of from by another code.
}