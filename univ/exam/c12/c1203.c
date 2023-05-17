#include "ft_list.h"

t_list	*ft_list_last(t_list	*begin_list)
{
	if (begin_list == NULL)
		return (NULL);
	if (begin_list->next != NULL)
		return (ft_list_last(begin_list->next));
	else
		return (begin_list);	
}

// int main()
// {
// 	t_list *begin_list = NULL;
// 	int a = 42;
// 	int b = 43;
// 	int *c;

// 	ft_list_push_front(&begin_list, &b);
// 	c = begin_list->data;
// 	printf("%d\n", *c);
// 	ft_list_push_front(&begin_list, &a);
// 	c = begin_list->data;
// 	printf("%d\n", *c);
// 	ft_list_push_front(&begin_list, &a);
// 	ft_list_push_front(&begin_list, &a);
// 	ft_list_push_front(&begin_list, &a);
// 	c = ft_list_last(begin_list)->data;		
// 	printf("%d\n", *c);
// 	return (0);
// }