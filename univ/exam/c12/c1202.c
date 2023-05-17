#include "ft_list.h"

int	ft_list_size(t_list	*begin_list)
{
	if (begin_list == NULL)
		return (0);
	if (begin_list->next != NULL)
		return (1 + ft_list_size(begin_list->next));
	else
		return (1);
	
}

int main()
{
	t_list *begin_list = NULL;
	int a = 42;
	int b = 43;
	int *c;
	int	size;

	ft_list_push_front(&begin_list, &a);
	c = begin_list->data;
	printf("%d\n", *c);
	ft_list_push_front(&begin_list, &b);
	c = begin_list->data;
	printf("%d\n", *c);
	ft_list_push_front(&begin_list, &b);
	ft_list_push_front(&begin_list, &b);
	ft_list_push_front(&begin_list, &b);
	size = ft_list_size(begin_list);
	printf("%d\n", size);
	return (0);
}