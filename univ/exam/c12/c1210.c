#include "ft_list.h"

int	ft_strcmp(void *a, void *b)
{
	char	*dest = (char*)a;
	char	*src = (char*)b;
	int		i;

	i = 0;
	while (dest[i] != '\0' && src[i] != '\0' && dest[i] == src[i])
		i++;
	return (dest[i]-src[i]);
}

void 	ft_putstr(void *data)
{
	char *converted;

	converted = (char*)data;
	printf("%s\n", converted);
}

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
	while (begin_list != NULL)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

int main(void)
{
	char *strs[]={"1","a", "bb", "ab","dddd"};
	t_list  *list;
	char data_ref[]="a";

	list = ft_list_push_strs(5, strs);
	ft_list_foreach_if(list, ft_putstr, data_ref, ft_strcmp);
	
	t_list *current;
	while(list != NULL)
	{
		current = list->next;
		free(list);
		list = current;
	}
	return (0);
}