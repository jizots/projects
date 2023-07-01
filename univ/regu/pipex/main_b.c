/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:51:52 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/30 19:37:48 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

int	main(int ac, char **av, char *envp[])
{
	t_cmds	data;

	if (ac < 5)
		return (ft_mes_error
			("Error. Entry 'here_doc' [cmd] [cmd] [out_file]\n"));
	if (ft_init_data(&data, ac, av, envp) != 0)
		return (EXIT_FAILURE);
	if (data.delim == HERE_DOC)
	{
		if (ft_here_doc(&data) != 0)
			return (EXIT_FAILURE);
	}
	else if (ft_fork_for_infile(&data) != 0)
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

// __attribute__((destructor))
// static void destructor()
// {
// 	system("leaks -q pipex");
// }