#include "pipex_b.h"

int	ft_here_doc(char **av)
{
	pid_t	pid;
	char	*line;
	int		fd_tmp;
	int		stdin_fd;

	fd_tmp = open(".temphere", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd_tmp == -1)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
	{
		stdin_fd = dup(STDIN_FILENO);
		line = "";
		while (1)
		{
			line = get_next_line(stdin_fd);
			if (line == NULL)
				break ;
			if ((ft_strncmp(av[2], line, ft_strlen(line) - 1)) == 0
				&& ft_strlen(av[2]) == (ft_strlen(line) - 1))
			{
				free (line);
				break ;
			}
			else
			{
				ft_putstr_fd(line, fd_tmp);
				free (line);
			}
		}
		close(fd_tmp);
		exit(EXIT_SUCCESS);
	}
	if (ft_wait_judge_child(pid) != 0)
		return (EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

int main(int ac, char **av, char *envp[])
{
	t_cmds	data;

	if (ac < 5)
		return (ft_mes_error("Error. Entry [in_file] [cmd] [cmd] [out_file]\n"));
	if (ft_init_data(&data, ac, av, envp) != 0)
		return (EXIT_FAILURE);
	//for here
	if (ft_strstr("here_doc", av[1]) != NULL)
	{
		if (ft_here_doc(av) != 0)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	//end for here
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