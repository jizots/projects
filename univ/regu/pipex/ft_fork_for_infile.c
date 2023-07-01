/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_for_infile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:37 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/01 12:29:58 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_infile_to_pipe(t_cmds *data, char *filename)
{
	if (close(data->in_pipefd[0]) == -1)
		exit(ft_print_perror("close data->in_pipefd[0]-infile"));
	data->fd_stdin = open(filename, O_RDONLY);
	if (data->fd_stdin >= 0)
	{
		if (dup2 (data->fd_stdin, STDIN_FILENO) == -1)
			exit (ft_print_perror("dup2 data->fd_stdin"));
		if (close (data->fd_stdin) == -1)
			exit(ft_print_perror("close data->fd_stdin"));
		if (dup2 (data->in_pipefd[1], STDOUT_FILENO) == -1)
			exit(ft_print_perror("dup2 in_pipefd[1]-infile"));
		if (close(data->in_pipefd[1]) == -1)
			exit(ft_print_perror("close in_pipefd[1]-infile"));
		if (execve(data->path_cmd, data->matrix_cmd, data->matrix_env) == -1)
		{
			if (errno != EACCES && errno != ENOENT)
				exit(ft_print_perror(data->path_cmd));
		}
	}
	else if (data->fd_stdin < 0)
		ft_print_perror(filename);
	exit(EXIT_SUCCESS);
}

int	ft_fork_for_infile(t_cmds *data)
{
	pid_t	pid;

	data->matrix_cmd = ft_split(data->av[2], ' ');
	if (data->matrix_cmd == NULL)
		return (ft_free_allocates(data->matrix_epath, NULL, NULL, 1));
	if (ft_get_absolute_path(data) != 0)
		return (ft_free_allocates(data->matrix_cmd, NULL, NULL, 0));
	pid = fork();
	if (pid == 0)
		ft_infile_to_pipe(data, data->av[1]);
	if (ft_wait_judge_child(pid) != 0)
		return (ft_free_allocates
			(data->matrix_cmd, data->matrix_epath, data->path_cmd, 0));
	if (close(data->in_pipefd[1]) == -1)
		return (ft_print_perror("close in_pipefd[1]-main"));
	ft_free_allocates(data->matrix_cmd, NULL, data->path_cmd, 0);
	return (EXIT_SUCCESS);
}
