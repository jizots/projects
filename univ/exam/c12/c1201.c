#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*temp;
	
	temp = ft_create_elem(data);
	if (temp == NULL)
		return ;
	temp->next = *begin_list;
	*begin_list = temp;
}

// int main()
// {
// 	t_list **begin_list;
// 	int a = 42;
// 	int b = 43;
// 	int *c;

// 	ft_list_push_front(begin_list, &a);
// 	c = begin_list[0]->data;
// 	printf("%d\n", *c);
// 	ft_list_push_front(begin_list, &b);
// 	c = begin_list[0]->data;
// 	printf("%d\n", *c);
// 	c = begin_list[0]-> next ->data;
// 	printf("%d\n", *c);
// 	return (0);
// }