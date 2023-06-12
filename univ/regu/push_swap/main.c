#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*root;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');//input error action
		root = ft_make_initial_stack(av, root);
	}
	else if (ac > 2)
		root = ft_make_initial_stack(&av[1], root);
	if (root == NULL)
	{
		write (1, "Error\n", 6);
		return (-1);
	}
	root = ft_push_swap(root);
while(root->content != NULL)
{
printf("->%d\n", *(int *)(root->content));
root = root->next;
}
	ft_delete_datas(root);
	return (0);
}