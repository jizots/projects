/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_for_outfile.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:43 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/28 14:53:24 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

static int	ft_pipe_to_outfile(int *in_pipefd, char **matrix_cmd,
	char *fullpath, char *filename)
{
	int	fdw;

	fdw = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fdw < 0)
		exit(ft_print_perror(filename));
	if (dup2 (in_pipefd[0], STDIN_FILENO) == -1)
		exit(ft_print_perror("dup2 in_pipefd[0]-outfile"));
	if (dup2 (fdw, STDOUT_FILENO) == -1)
		exit(ft_print_perror("dup2 outfile"));
	if (close (fdw) == -1)
		exit(ft_print_perror("close outfile"));
	if (close(in_pipefd[0]) == -1)
		exit(ft_print_perror("close in_pipefd[0]-outfile"));
	if (execve(fullpath, matrix_cmd, environ) == -1)
	{
		if (errno != EACCES && errno != ENOENT)
			exit(ft_print_perror(fullpath));
	}
	exit(EXIT_SUCCESS);
}

int	ft_fork_for_outfile(int *in_pipefd, char **av, int ac)
{
	pid_t	pid;
	char	**matrix_cmd;
	char	**matrix_path;
	char	*fullpath;

	if (ft_search_envpaths(&matrix_path) == NULL)
		return (EXIT_FAILURE);
	matrix_cmd = ft_split(av[ac - 2], ' ');
	if (matrix_cmd == NULL)
		return (ft_free_allocates(matrix_path, NULL, NULL, 1));
	if (ft_get_absolute_path(matrix_path, matrix_cmd[0], &fullpath) != 0)
		return (ft_free_allocates(matrix_cmd, NULL, NULL, 0));
	pid = fork();
	if (pid == 0)
		ft_pipe_to_outfile(in_pipefd, matrix_cmd, fullpath, av[ac - 1]);
	if (ft_wait_judge_child(pid) != 0)
		return (ft_free_allocates(matrix_cmd, matrix_path, fullpath, 0));
	if (close(in_pipefd[0]) == -1)
		return (ft_print_perror("close out_pipefd[0]-main"));
	ft_free_allocates(matrix_cmd, matrix_path, fullpath, 0);
	return (EXIT_SUCCESS);
}
