#include "pipex_b.h"

int	ft_here_doc(int *in_pipefd, char **av)
{
	pid_t	pid;
	char	*line;

	pid = fork();
	if (pid == 0)
	{
		if (close(in_pipefd[0]) == -1)
			exit(ft_print_perror("close in_pipefd[0]-first"));
puts("close in pipe ok");
		// if (dup2(in_pipefd[1], STDOUT_FILENO) == -1)
		// 	exit(ft_print_perror("dup2 fdr"));
puts("dup ok");
		if (close(in_pipefd[1]) == -1)
			exit (ft_print_perror("dup2 fdr"));
		line = (char *)&pid;
		while (line)
		{
puts("in while");
			line = get_next_line(STDIN_FILENO);
printf("line = %s\n", line);
			if (ft_strstr(av[2], line) == NULL)
			{
puts("strstr error");
				write (STDOUT_FILENO, line, ft_strlen(line));
				free (line);
			}
			else
{puts("break");
				break ;
}
		}
puts("end while");
		exit(EXIT_SUCCESS);
	}
	if (ft_wait_judge_child(pid) != 0)
		return (EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	int		in_pipefd[2];
	int		out_pipefd[2];

	if (ac < 5)
		return (ft_mes_error("Error. Entry [in_file] [cmd] [cmd] [out_file]\n"));
	if (pipe(in_pipefd) == -1)
		return (ft_print_perror("pipe"));
	//for here
	if (ft_strstr("here_doc", av[1]) != NULL)
	{
puts("here");
		if (ft_here_doc(in_pipefd, av) != 0)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	//end for here
	else if (ft_fork_for_infile(in_pipefd, av) != 0)
		return (EXIT_FAILURE);
	if (6 <= ac)
	{
		if (ft_fork_for_repeat_pipe(out_pipefd, in_pipefd, av, ac) != 0)
			return (EXIT_FAILURE);
	}
	if (ft_fork_for_outfile(in_pipefd, av, ac) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}