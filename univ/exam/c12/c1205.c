#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list *newlist;
	t_list *current;
	int		i;

	i = 0;
	current = NULL;
	while (i < size)
	{
		newlist = ft_create_elem(strs[i]);
		if (newlist == NULL)
			return NULL;
		newlist->next = current;
		current = newlist; 
		i++;
	}
	return (newlist);
}

// int	main(void)
// {
// 	char *strs[]={"a", "bb", "CCC","dddd"};
// 	t_list  *list;
// 	char	*str;

// 	list = ft_list_push_strs(4, strs);
// 	while (1)
// 	{
// 		str =  (char*)list->data;
// 		printf("%s\n", str);
// 		if (list->next == NULL)
// 			break ;
// 		list = list->next;
// 	}
// }