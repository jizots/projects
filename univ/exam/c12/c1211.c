#include "ft_list.h"

int	ft_strcmp(void *a, void *b)
{
	char	*s1 = (char*)a;
	char	*s2 = (char*)b;
	int		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

t_list	*ft_list_find(t_list *begin_list, void	*data_ref, int (*cmp)())
{
	while (begin_list != NULL)
	{
		if ((*cmp)(begin_list->data, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
puts("panetrate");
	return (NULL);
}

int main(void)
{
	char *strs[]={"1","aa", "bb", "CCC","dddd"};
	t_list  *list;
	char data_ref[]="aa";

	list = ft_list_push_strs(5, strs);
	list = ft_list_find(list, data_ref, ft_strcmp);

	if (list != NULL)
	{
		char *c;
		c = (char*)list->data;
		printf("returned data; %s\n",c);
	}

	t_list *current;
	while(list != NULL)
	{
		current = list->next;
		free(list);
		list = current;
	}
	return (0);
}