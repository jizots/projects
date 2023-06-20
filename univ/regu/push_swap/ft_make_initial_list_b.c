/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_initial_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:55:07 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:55:09 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_b.h"

static t_list	*ft_fail_value(t_list *root, int *p_value)
{
	free(p_value);
	if (root != NULL)
		ft_delete_datas(root);
	return (NULL);
}

int	ft_check_duplicate(t_list *stack, int value)
{
	if (stack == NULL)
		return (0);
	while (stack->cont != NULL)
	{
		if (*(stack->cont) == value)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

t_list	*ft_make_initial_stack(char **args)
{
	int		i;
	t_list	*root;
	int		*p_value;
	char	*flag_error;

	i = 0;
	root = NULL;
	while (args[i] != NULL)
	{
		p_value = malloc (sizeof(int) * 1);
		if (p_value == NULL)
		{
			ft_delete_datas(root);
			return (NULL);
		}
		flag_error = args[i];
		*p_value = ft_atoi(args[i++], &flag_error);
		if (flag_error == NULL || ft_check_duplicate(root, *p_value) == -1)
			return (ft_fail_value(root, p_value));
		root = ft_add_stack(root, p_value);
	}
	return (root);
}
