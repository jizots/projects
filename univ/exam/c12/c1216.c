#include "ft_list.h"

int	ft_strcmp(void *a, void *b)
{
	char	*str1 = (char*)a;
	char	*str2 = (char*)b;
	int		i = 0;

	while (str1[i] == str2[i] && str1[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}

void	ft_insert_list(t_list *last, t_list *add_list, t_list *current, t_list **begin_list)
{
	if (last == NULL)
		*begin_list = add_list;
	else
		last->next = add_list;
	add_list->next = current;
puts("inserted");
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*current;
	t_list	*last;
	t_list	*add_list;
	int		flag;

	flag = 0;	
	add_list = ft_create_elem(data);
	current = *begin_list;
	last	= NULL;
	while (current != NULL)
	{
		if ((*cmp)(current->data, data) > 0)
		{
			flag = 1;
			ft_insert_list(last, add_list, current, begin_list);
			break ;
		}
		last = current;
		current = current->next;
	}
	if (flag == 0)
		last->next = add_list;
}

int main(void)
{
	t_list	*begin_list;
	char	*origin_strs[] = {"bcb", "bb", "aab", "aa", "11", NULL};
	size_t	len_strs;
	char	data[] = "bb";

	//len origin
	len_strs = 0;
	while (origin_strs[len_strs])
		len_strs++;

	//allocate memory & make list
	begin_list = ft_list_push_strs(len_strs, origin_strs);
	
	//verify made data
	t_list	*current;
	char	*c;

current = begin_list;
while (current != NULL)
{
	c = current->data;
	printf("data : %s\n",c);
	current = current->next;
}

	
	//pass to main func
	ft_sorted_list_insert(&begin_list, data, ft_strcmp);
puts("back to main");
	//verify main func
	current = begin_list;
	while (current != NULL)
	{
		c = current->data;
		printf("data : %s\n",c);
		current = current->next;
	}

	//free malloc
	current = begin_list;
	while (current != NULL)
	{
		current = current->next;
		free(begin_list);
		begin_list = current;
	}
	return (0);
}