/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_for_infile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:37 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/28 14:52:14 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

static int	ft_infile_to_pipe(int *in_pipefd, char **matrix_cmd,
	char *fullpath, char *filename)
{
	int		fdr;

	if (close(in_pipefd[0]) == -1)
		exit(ft_print_perror("close in_pipefd[0]-first"));
	fdr = open(filename, O_RDONLY);
	if (fdr >= 0)
	{
		if (dup2 (fdr, STDIN_FILENO) == -1)
			exit (ft_print_perror("dup2 fdr"));
		if (close (fdr) == -1)
			exit(ft_print_perror("close fdr"));
		if (dup2 (in_pipefd[1], STDOUT_FILENO) == -1)
			exit(ft_print_perror("dup2 in_pipefd[1]-first"));
		if (close(in_pipefd[1]) == -1)
			exit(ft_print_perror("close in_pipefd[1]-first"));
		if (execve(fullpath, matrix_cmd, environ) == -1)
		{
			if (errno != EACCES && errno != ENOENT)
				exit(ft_print_perror(fullpath));
		}
	}
	else if (fdr < 0)
		ft_print_perror(filename);
	exit(EXIT_SUCCESS);
}

int	ft_fork_for_infile(int *in_pipefd, char **av)
{
	pid_t	pid;
	char	**matrix_cmd;
	char	**matrix_path;
	char	*fullpath;

	if (ft_search_envpaths(&matrix_path) == NULL)
		return (EXIT_FAILURE);
	matrix_cmd = ft_split(av[2], ' ');
	if (matrix_cmd == NULL)
		return (ft_free_allocates(matrix_path, NULL, NULL, 1));
	if (ft_get_absolute_path(matrix_path, matrix_cmd[0], &fullpath) != 0)
		return (ft_free_allocates(matrix_cmd, NULL, NULL, 0));
	pid = fork();
	if (pid == 0)
		ft_infile_to_pipe(in_pipefd, matrix_cmd, fullpath, av[1]);
	if (ft_wait_judge_child(pid) != 0)
		return (ft_free_allocates(matrix_cmd, matrix_path, fullpath, 0));
	if (close(in_pipefd[1]) == -1)
		return (ft_print_perror("close in_pipefd[1]-main"));
	ft_free_allocates(matrix_cmd, matrix_path, fullpath, 0);
	return (EXIT_SUCCESS);
}
