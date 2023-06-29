/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:50:45 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/29 19:27:51 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	printmatrix(char **matrix, char *name_item)
// {
// 	printf ("-->%s<--\n", name_item);
// 	for (int i = 0; matrix[i] != NULL; i++)
// 		printf("%s\n", matrix[i]);
// }

int	main(int ac, char *av[], char *envp[])
{
	t_cmds	data;

	if (ac < 5)
		return (ft_mes_error("Error. Entry [in_file] [cmd] [cmd] [out_file]\n"));
	if (ft_init_data(&data, ac, av, envp) != 0)
		return (EXIT_FAILURE);
	if (ft_fork_for_infile(&data) != 0)
		return (EXIT_FAILURE);
	if (6 <= ac)
	{
		if (ft_fork_for_repeat_pipe(&data) != 0)
			return (EXIT_FAILURE);
	}
	if (ft_fork_for_outfile(&data) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q pipex");
}