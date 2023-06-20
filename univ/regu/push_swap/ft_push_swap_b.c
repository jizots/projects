/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:55:17 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/18 19:55:19 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_b.h"

static t_list	*ft_create_bstack(void)
{
	t_list	*new;

	new = malloc (sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->cont = NULL;
	new->prev = new;
	new->next = new;
	return (new);
}

void	ft_exec_instr(t_list **sta, t_list **stb, char *instr)
{
	if (ft_strstr(instr, "sa") != NULL)
		*sta = b_swap_single(*sta);
	else if (ft_strstr(instr, "sb") != NULL)
		*stb = b_swap_single(*stb);
	else if (ft_strstr(instr, "ss") != NULL)
		b_swap_double(sta, stb);
	else if (ft_strstr(instr, "pa") != NULL)
		b_push(stb, sta);
	else if (ft_strstr(instr, "pb") != NULL)
		b_push(sta, stb);
	else if (ft_strstr(instr, "rra") != NULL)
		*sta = b_r_rotate(*sta);
	else if (ft_strstr(instr, "rrb") != NULL)
		*stb = b_r_rotate(*stb);
	else if (ft_strstr(instr, "rrr") != NULL)
		b_r_rotate_double(sta, stb);
	else if (ft_strstr(instr, "ra") != NULL)
		*sta = b_rotate(*sta);
	else if (ft_strstr(instr, "rb") != NULL)
		*stb = b_rotate(*stb);
	else if (ft_strstr(instr, "rr") != NULL)
		b_rotate_double(sta, stb);
}

t_list	*b_push_swap(t_list *sta)
{
	t_list	*stb;
	char	*instr;

	stb = ft_create_bstack();
	if (stb == NULL)
	{
		ft_put_error(sta);
		return (NULL);
	}
	while (1)
	{
		instr = ft_get_next_line();
		if (instr == NULL)
			break ;
		ft_exec_instr(&sta, &stb, instr);
		free (instr);
	}
	if (ft_ascending_sorted(sta) == 0 && stb->cont == NULL)
		write(1, "OK\n", 3);
	else
		write(STDERR_FILENO, "KO\n", 3);
	ft_delete_datas(stb);
	return (sta);
}
