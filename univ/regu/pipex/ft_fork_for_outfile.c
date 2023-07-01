/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_for_outfile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:43 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/30 19:35:48 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_pipe_to_outfile(t_cmds *data, char *filename)
{
	if (data->delim == HERE_DOC)
		data->fd_stdout = open
			(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
	else
		data->fd_stdout = open
			(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (data->fd_stdout >= 0)
	{
		if (dup2 (data->in_pipefd[0], STDIN_FILENO) == -1)
			exit(ft_print_perror("dup2 in_pipefd[0]-outfile"));
		if (dup2 (data->fd_stdout, STDOUT_FILENO) == -1)
			exit(ft_print_perror("dup2 outfile"));
		if (close (data->fd_stdout) == -1)
			exit(ft_print_perror("close outfile"));
		if (close(data->in_pipefd[0]) == -1)
			exit(ft_print_perror("close in_pipefd[0]-outfile"));
		if (execve(data->path_cmd, data->matrix_cmd, data->matrix_env) == -1)
		{
			if (errno != EACCES && errno != ENOENT)
				exit(ft_print_perror(data->path_cmd));
		}
	}
	else if (data->fd_stdout < 0)
		exit(ft_print_perror(filename));
	exit(EXIT_SUCCESS);
}

int	ft_fork_for_outfile(t_cmds *data)
{
	pid_t	pid;

	data->matrix_cmd = ft_split(data->av[data->ac - 2], ' ');
	if (data->matrix_cmd == NULL)
		return (ft_free_allocates(data->matrix_epath, NULL, NULL, 1));
	if (ft_get_absolute_path(data) != 0)
		return (ft_free_allocates(data->matrix_cmd, NULL, NULL, 0));
	pid = fork();
	if (pid == 0)
		ft_pipe_to_outfile(data, data->av[data->ac - 1]);
	if (ft_wait_judge_child(pid) != 0)
		return (ft_free_allocates
			(data->matrix_cmd, data->matrix_epath, data->path_cmd, 0));
	if (close(data->in_pipefd[0]) == -1)
		return (ft_print_perror("close out_pipefd[0]-main"));
	ft_free_allocates(data->matrix_cmd, data->matrix_epath, data->path_cmd, 0);
	return (EXIT_SUCCESS);
}
