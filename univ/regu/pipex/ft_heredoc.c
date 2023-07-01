/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:51:52 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/30 19:36:49 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_b.h"

int	ft_heredoc_from_stdin(t_cmds *data)
{
	char	*line;

	line = "";
	while (1)
	{
		write(STDERR_FILENO, "$>", 2);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL && ft_mes_error("Error. here_gnl"))
			return (EXIT_FAILURE);
		if ((ft_strncmp(data->av[2], line, ft_strlen(line) - 1)) == 0
			&& ft_strlen(data->av[2]) == (ft_strlen(line) - 1))
		{
			free (line);
			break ;
		}
		else
			ft_putstr_fd(line, STDOUT_FILENO);
		free (line);
	}
	return (EXIT_SUCCESS);
}

int	ft_here_doc(t_cmds *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (close(data->in_pipefd[0]) == -1)
			ft_print_perror("close in_pipefd[0]");
		if (dup2(data->in_pipefd[1], STDOUT_FILENO) == -1)
			exit (ft_print_perror("dup2 data->fd_stdin"));
		if (close(data->in_pipefd[1]) == -1)
			ft_print_perror("close in_pipefd[1]");
		ft_heredoc_from_stdin(data);
		exit(EXIT_SUCCESS);
	}
	else if (ft_wait_judge_child(pid) != 0)
		return (EXIT_FAILURE);
	if (close(data->in_pipefd[1]) == -1)
		return (ft_print_perror("close in_pipefd[1]"));
	return (EXIT_SUCCESS);
}
