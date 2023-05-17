#include "ft_list.h"

int	ft_strcmp(void *a, void *b)
{
	char	*s1 = (char*)a;
	char	*s2 = (char*)b;
	int		i;
	
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_swap(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*begin_prev;
	t_list	*comp;
	t_list	*comp_prev;
	t_list	*temp;
	t_list	*current;

	begin_prev = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		comp = current->next;
		comp_prev = current;
		while (comp != NULL)
		{
			if ((*cmp)(current->data, comp->data) > 0)
			{
				if (begin_prev != NULL)
					begin_prev->next = comp;
				temp = current->next;
				current->next = comp->next;
				if (comp_prev != current)
				{	
					comp->next = temp;
					comp_prev->next = current;
				}
				else
				{
					comp->next = current;
				}
				temp = comp;
				comp = current;
				current = temp;
				if (begin_prev == NULL)
					*begin_list = current;
			}
			else
			{
				comp_prev = comp;
			}
			comp = comp->next;
		}
		begin_prev = current;
		current = current->next;
	}
}


int main(void)
{
	t_list	**begin_list;
	size_t	len_list;
	size_t	i = 0;
	char	*data[] = {"abcc","aaa", "bb", "1","abca", NULL};

	//len_list
	len_list = 0;
	while (data[i])
	{
		i++;
		len_list++;
	}
	
	//keep pointer memory
	begin_list = malloc(sizeof(t_list*) * (len_list + 1));
	if (begin_list == NULL)
	{
		puts("*begin_list malloc error");
		return (0);
	}
	begin_list[len_list] = NULL;

	//entry data to struct
	i = 0;
	while (i < len_list)
	{
		begin_list[i] = malloc(sizeof(t_list));
		if (begin_list[i] == NULL)
		{
			puts("t_list malloc error");
			return (0);
		}
		begin_list[i]->data = data[i];
		i++;
	}
	//entry next to struct
	i = 0;
	while (i < len_list)
	{
		begin_list[i]->next = begin_list[i + 1];
		i++;
	}
	//pass to main func
	ft_list_sort(begin_list, ft_strcmp);
	//verify main func
	t_list	*current;
	char	*c;

	current = begin_list[0];
	while (current != NULL)
	{
		c = (char*)current->data;
		printf ("sorted data:%s\n",c);
		current = current->next;
	}

	//free malloc
	current = begin_list[0];
	i = 0;
	while (current != NULL)
	{
		current = current->next;
		free(begin_list[i++]);
	}

	free(begin_list);
	return (0);
}