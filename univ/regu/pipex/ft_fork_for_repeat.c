/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_for_repeat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:50 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/28 14:55:43 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

static int	fr_pipe_to_pipe(int *in_pipefd, int *out_pipefd,
	char **matrix_cmd, char *fullpath)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (close(out_pipefd[0]) == -1)
			exit(ft_print_perror("close out_pipefd[0]-repeat"));
		if (dup2(in_pipefd[0], STDIN_FILENO) == -1)
			exit(ft_print_perror("dup2 in_pipefd[0]-repeat"));
		if (dup2(out_pipefd[1], STDOUT_FILENO) == -1)
			exit(ft_print_perror("dup2 out_pipefd[1]-repeat"));
		if (close(out_pipefd[1]) == -1)
			exit(ft_print_perror("close out_pipefd[1]-repeat"));
		if (close(in_pipefd[0]) == -1)
			exit(ft_print_perror("close in_pipefd[0]-repeat"));
		if (execve(fullpath, matrix_cmd, environ) == -1)
		{
			if (errno != EACCES && errno != ENOENT)
				exit(ft_print_perror(fullpath));
		}
	}
	return (ft_wait_judge_child(pid));
}

int	ft_fork_for_repeat_pipe(int *out_pipefd, int *in_pipefd, char **av, int ac)
{
	int		i;
	char	**matrix_cmd;
	char	**matrix_path;
	char	*fullpath;

	i = 3;
	while ((i + 2) < ac)
	{
		if (pipe(out_pipefd) == -1)
			return (ft_print_perror("pipe"));
		matrix_cmd = ft_split(av[i++], ' ');
		if (matrix_cmd == NULL)
			return (ft_mes_error("Error. Split can't allocate.\n"));
		if (ft_search_envpaths(&matrix_path) == NULL)
			return (ft_free_allocates(matrix_cmd, NULL, NULL, 1));
		if (ft_get_absolute_path(matrix_path, matrix_cmd[0], &fullpath) != 0)
			return (ft_free_allocates(matrix_cmd, NULL, NULL, 0));
		if (fr_pipe_to_pipe(in_pipefd, out_pipefd, matrix_cmd, fullpath) != 0)
			return (ft_free_allocates(matrix_cmd, matrix_path, fullpath, 0));
		in_pipefd[0] = out_pipefd[0];
		if (close(out_pipefd[1]) == -1)
			exit(ft_print_perror("close out_pipefd[1]-main"));
		ft_free_allocates(matrix_cmd, matrix_path, fullpath, 0);
	}
	return (EXIT_SUCCESS);
}
