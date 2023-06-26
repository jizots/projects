#include "pipex.h"

extern char	**environ;

void	printmatrix(char **matrix, char *name_item)
{
	printf ("-->%s<--\n", name_item);
	for (int i = 0; matrix[i] != NULL; i++)
		printf("%s\n", matrix[i]);
}

int	main(int ac, char *av[])
{
	size_t	i;
	int		in_pipefd[2];
	int		out_pipefd[2];

	if (ac < 5)
		return (ft_mes_error("Error. Entry [in_file] [cmd] [cmd] [out_file]\n"));
	i = 2;
	if (pipe(in_pipefd) == -1) 
		return (ft_print_perror("pipe"));
	if (ft_fork_for_infile(in_pipefd, av) != 0)
		return (EXIT_FAILURE);
	if (6 <= ac)
	{
puts("go repeat");
		if (ft_fork_for_repeat_pipe(out_pipefd, in_pipefd, av, ac) != 0)
			return (EXIT_FAILURE);
	}
	if (ft_fork_for_outfile(in_pipefd, av, ac) != 0)
		return (EXIT_FAILURE);
	if (close(out_pipefd[0]) == -1)
		return (ft_print_perror("close out_pipefd[0]-main"));
	return (EXIT_SUCCESS);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q pipex");
}