#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while ( 0 < nbr--)
	{
		if (begin_list->next == NULL || begin_list == NULL)
			return (NULL);
		begin_list = begin_list->next;
	}
	return (begin_list);
}

int	main(void)
{
	char *strs[]={"a", "bb", "CCC","dddd"};
	t_list  *list;
	char	*str;

	list = ft_list_push_strs(4, strs);
	list = ft_list_at(list, 0);
	if (list == NULL) puts("null");
	else {str =  (char*)list->data; printf("%s\n", str);}
	return 0;
}