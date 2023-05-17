#include "ft_list.h"
void	ft_input_next(t_list *next, t_list *list)
{
	list->next = next;
}

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	return (1 + ft_list_size(begin_list->next));
}

void	ft_list_reverse(t_list **begin_list)
{
	unsigned int	len_list;
	t_list			*next_first;
	t_list			*next_second;

	if (*begin_list == NULL)
		return ;
	len_list = ft_list_size(*begin_list);
	next_first = (*begin_list)->next;
	(*begin_list)->next = NULL;
	while (1 < len_list--)
	{
		next_second = next_first->next;
		ft_input_next((*begin_list), next_first);
		*begin_list = next_first;
		next_first = next_second;
	}
}

int	main(void)
{
	char *strs[]={"1","a", "bb", "CCC","dddd"};
	t_list  *list;
	char	*str;

	list = ft_list_push_strs(5, strs);
	ft_list_reverse(&list);
	while (1)
	{
		str =  (char*)list->data;
		printf("%s\n", str);
		if (list->next == NULL)
			break ;
		list = list->next;
	}
	
	while (1)
	{
		t_list *next;
		next = list->next;
		free(list);
		if (next == NULL)
			break ;
		list = next;
	}
	return (0);
}