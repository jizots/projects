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

void	ft_insert_list(t_list *last, t_list *list2, t_list *current, t_list **begin_list)
{
	if (last == NULL)
		*begin_list = list2;
	else
		last->next = list2;
	list2->next = current;
}

void	ft_sorted_list_merge(t_list **begin_list, t_list *list2, int (*cmp)(void*, void*))
{
	t_list	*current;
	t_list	*last;
	t_list	*origin_list2_next;
	int		flag;

	last	= NULL;
	current = *begin_list;
	while (list2 != NULL)
	{
		flag = 0;
		origin_list2_next = list2->next;
		while (current != NULL)
		{
			if (cmp(current->data, list2->data) > 0)
			{
				ft_insert_list(last, list2, current, begin_list);
				flag = 1;
				break ;
			}
			last = current;
			current = current->next;
		}
		if (flag == 0)
		{
			last->next = list2;
			break ;
		}
		list2 = origin_list2_next;
	}
}

int main(void)
{
	t_list	*begin_list;
	t_list	*list2;
	char	*strs1[] = {"bcb", "bb", "aab", "aa", "11", NULL};
	char	*strs2[] = {"dbbb", "daca", "daaa", "da", "d10", NULL};
	size_t	len_strs;


	//len origin allocate memory
	len_strs = 0;
	while (strs1[len_strs])
		len_strs++;
	begin_list = ft_list_push_strs(len_strs, strs1);

	len_strs = 0;
	while (strs2[len_strs])
		len_strs++;
	list2 = ft_list_push_strs(len_strs, strs2);

	//verify made data
	t_list	*current;
	char	*c;
	
	//pass to main func
	ft_sorted_list_merge(&begin_list, list2, ft_strcmp);
puts("back to main");

	//verify main func
	current = begin_list;
	while (current != NULL)
	{
		c = current->data;
		printf("verify data : %s\n",c);
		current = current->next;
	}

	//free malloc
	current = begin_list;
	while (current != NULL)
	{
		current = current->next;
		free(begin_list->data);
		free(begin_list);
		begin_list = current;
	}
	return (0);
}