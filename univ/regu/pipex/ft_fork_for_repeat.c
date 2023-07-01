/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_for_repeat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:50 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/30 19:36:01 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

static int	fr_pipe_to_pipe(t_cmds *data)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (close(data->out_pipefd[0]) == -1)
			exit(ft_print_perror("close out_pipefd[0]-repeat"));
		if (dup2(data->in_pipefd[0], STDIN_FILENO) == -1)
			exit(ft_print_perror("dup2 in_pipefd[0]-repeat"));
		if (dup2(data->out_pipefd[1], STDOUT_FILENO) == -1)
			exit(ft_print_perror("dup2 out_pipefd[1]-repeat"));
		if (close(data->out_pipefd[1]) == -1)
			exit(ft_print_perror("close out_pipefd[1]-repeat"));
		if (close(data->in_pipefd[0]) == -1)
			exit(ft_print_perror("close in_pipefd[0]-repeat"));
		if (execve(data->path_cmd, data->matrix_cmd, data->matrix_env) == -1)
		{
			if (errno != EACCES && errno != ENOENT)
				exit(ft_print_perror(data->path_cmd));
		}
	}
	return (ft_wait_judge_child(pid));
}

int	ft_fork_for_repeat_pipe(t_cmds *data)
{
	int		i;

	i = 3;
	while ((i + 2) < data->ac)
	{
		if (pipe(data->out_pipefd) == -1)
			return (ft_print_perror("pipe"));
		data->matrix_cmd = ft_split(data->av[i++], ' ');
		if (data->matrix_cmd == NULL)
			return (ft_mes_error("Error. Split can't allocate.\n"));
		if (ft_get_absolute_path(data) != 0)
			return (ft_free_allocates(data->matrix_cmd, NULL, NULL, 0));
		if (fr_pipe_to_pipe(data) != 0)
			return (ft_free_allocates
				(data->matrix_cmd, data->matrix_epath, data->path_cmd, 0));
		data->in_pipefd[0] = data->out_pipefd[0];
		if (close(data->out_pipefd[1]) == -1)
			exit(ft_print_perror("close out_pipefd[1]-main"));
		ft_free_allocates(data->matrix_cmd, NULL, data->path_cmd, 0);
	}
	return (EXIT_SUCCESS);
}
