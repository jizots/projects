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

void	free_fct(void *data)
{
	free(data);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)())
{
	// t_list *current = *begin_list;
	// t_list *prev = NULL;
	// t_list *temp;

	// while (current != NULL)
	// {
	// 	if (cmp(current->data, data_ref) == 0)
	// 	{
	// 		if (prev)
	// 		{
	// 			prev->next = current->next;
	// 		}
	// 		else
	// 		{
	// 			*begin_list = current->next;
	// 		}
	// 		temp = current;
	// 		current = current->next;
	// 		free_fct(temp->data);
	// 		free(temp);
	// 	}
	// 	else
	// 	{
	// 		prev = current;
	// 		current = current->next;
	// 	}
	// }

	int	i;
	int	liftup;

	i = 0;
	while (begin_list[i] != NULL)
	{
		while ((*cmp)(begin_list[i]->data, data_ref) == 0)
		{
			liftup = i;
			while (1) //liftup
			{
				begin_list[liftup] = begin_list [liftup + 1];
				if (begin_list[liftup] == NULL)
					break ;
				liftup++;
			}
			if (i > 0)
			{
				begin_list[i - 1]->next = begin_list[i];
			}
			(*free_fct)(begin_list[i]->data);
		}
		i++;
	}
}

int main(void)
{
	t_list	**begin_list;
	size_t	len_list;
	size_t	i = 0;
	char	*data[] = {"aa","aa", "bb", "CCC","dddd", NULL};

	//len_list
	len_list = 0;
	while (data[i])
	{
		i++;
		len_list++;
	}
	printf("len_list: %d\n",len_list);
	
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

	//verify entry data
	t_list	*current;
	char	*c;
	current = begin_list[0];
	while (current != NULL)
	{
		c = (char*)current->data;
		printf ("entry data:%s\n",c);
		current = current->next;
	}

	//pass to main func
	char	data_ref[] = "aa";
	ft_list_remove_if(begin_list, data_ref, ft_strcmp, free_fct);

	//verify main func
	current = begin_list[0];
	while (current != NULL)
	{
		c = (char*)current->data;
		printf ("entry data:%s\n",c);
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