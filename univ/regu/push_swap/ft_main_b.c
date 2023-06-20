/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:48:10 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/20 19:48:13 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_b.h"

static void	ft_free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		free (args[i++]);
	free (args);
}

void	ft_delete_datas(t_list *stack)
{
	t_list	*next;

	while (stack->cont != NULL)
	{
		next = stack->next;
		free (stack->cont);
		free (stack);
		stack = next;
	}
	free (stack);
}

int	ft_put_error(t_list *root)
{
	if (root != NULL)
		ft_delete_datas(root);
	write (STDERR_FILENO, "Error\n", 6);
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
	if (roota == NULL)
		return (ft_put_error(roota));
	roota = b_push_swap(roota);
	if (roota == NULL)
		return (-1);
	ft_delete_datas(roota);
	return (0);
}

// __attribute__((destructor))
// static void destructor(){
// 	system("leaks -q checker");
// }
