#include "ft_list.h"

void	ft_list_merge(t_list **begin_list, t_list *add_list)
{
	t_list *current;

	if (*begin_list ==NULL)
	{
		return ;
	}
	current = *begin_list;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = add_list;
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

	//entry data to struct;
	t_list	*add_list;
	char	add_data[]="add last";

	add_list = ft_create_elem(add_data);
	char	*cc;
	cc = (char*)add_list->data;
	printf ("entry data:%s\n",cc);

	//add data
	ft_list_merge(begin_list, add_list);

	//verify main func
puts("verify main func");
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