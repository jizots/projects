#include "ft_list.h"

void 	ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *new_list;

    new_list = ft_create_elem(data);
    if (new_list == NULL)
        return ;
    if (*begin_list == NULL)
    {
        *begin_list = new_list;
        return ;
    }
    else
    {
        t_list *current = *begin_list;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_list;
    }
}

// int main()
// {
// 	t_list *begin_list = NULL;
// 	int a = 42;
// 	int b = 43;
// 	int *c;

// 	ft_list_push_back(&begin_list, &b);
// 	c = begin_list->data;
// 	printf("%d\n", *c);
// 	ft_list_push_back(&begin_list, &b);
// 	ft_list_push_back(&begin_list, &b);
// 	ft_list_push_back(&begin_list, &a);
// 	c = begin_list->data;
// 	printf("%d\n", *c);
// 	return (0);
// }

