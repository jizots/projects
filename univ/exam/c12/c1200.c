#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*tptr;

	tptr = malloc(sizeof(t_list));
	if (tptr == NULL)
		return NULL;
	tptr->next = NULL;
	tptr->data = data;
	return (tptr);
}

// int	main()
// {
// 	t_list *a;
// 	int idata = 42;
// 	int *c;

// 	a = ft_create_elem(&idata);
// 	c = (int*)(a->data);
// 	printf("%d\n", *c);
// 	printf("%s", a->next);
// 	return (0);
// }