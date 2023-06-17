#include "push_swap.h"

void printf_list(t_list *list)
{
	for (t_list *tmp = list; tmp->cont != NULL; tmp = tmp->next)
		printf("->%d\n", *(tmp->cont));
}

static void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		free (args[i++]);
	free (args);
}

static int	ft_put_error(t_list *root)
{
	if (root != NULL)
		ft_delete_datas(root);
	write (1, "Error\n", 6);
	return (-1);
}

int	main(int ac, char **av)
{
	t_list	*roota;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			return (-1);
		roota = ft_make_initial_stack(av);
	}
	else
		roota = ft_make_initial_stack(&av[1]);
	if (ac == 2)
		ft_free_args(av);
	if (roota == NULL || ft_lstsize(roota) == 1)
		return (ft_put_error(roota));
	roota = ft_push_swap(roota);
printf_list(roota);
	ft_delete_datas(roota);
	return (0);
}