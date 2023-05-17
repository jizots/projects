#include "ft_list.h"

void	free_fct(void *data)
{
char *c = (char *)data;
printf("%s,befor free\n",c);
	free(data);
printf("%s,after free\n",c);
}

void	ft_list_clear(t_list *begin_list, void	(*free_fct)(void *))
{
	t_list *tmplist;

	while(begin_list != NULL)
	{
		tmplist = begin_list->next;
		(*free_fct)(begin_list->data);
		free(begin_list);
		begin_list = tmplist;
	}
}

int	main(void)
{
	char *strs[]={"a", "bb", "CCC","dddd"};
	t_list  *list;
	char	*str;

	list = ft_list_push_strs(4, strs);
	while (1)
	{
		str =  (char*)list->data;
		printf("%s\n", str);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	list = ft_list_push_strs(4, strs);
	ft_list_clear(list, free_fct);
	return 0;
}