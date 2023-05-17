#include "ft_list.h"

void 	ft_putstr(void *data)
{
	char *converted;

	converted = (char*)data;
	printf("%s\n", converted);
}

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

int main(void)
{
	char *strs[]={"1","a", "bb", "CCC","dddd"};
	t_list  *list;

	list = ft_list_push_strs(5, strs);
	ft_list_foreach(list, ft_putstr);

	return (0);
}