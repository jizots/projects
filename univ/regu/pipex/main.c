#include "pipex.h"

extern char	**environ;

void	printmatrix(char **matrix, char *name_item)
{
	printf ("-->%s<--\n", name_item);
	for (int i = 0; matrix[i] != NULL; i++)
		printf("%s\n", matrix[i]);
}

void	ft_infile_pipefirst(char **av, int *fd_pipe, pid_t pid)
{
	int		fd_infile;
	int		status;
	char	**command_op;
	char	*paths;
	char	*full_path;

	fd_infile = open(av[1], O_RDONLY);
	if (fd_infile < 0)
	{
		ft_print_perror(av[1]);
		return (-1);
	}
	pid = fork();
	if (pid == 0)
	{
		command_op = ft_split(av[2], ' ');
		if (command_op == NULL)
			return (ft_mes_error("Error. Fail allocate memory.\n"));
		paths = ft_search_envpaths();
		if (paths == NULL)
			return (ft_free_matrix(command_op, NULL, 1));
		full_path = ft_get_absolute_path(paths, command_op[0]);
		if (full_path == NULL)
			return (ft_free_matrix(command_op, NULL, 0));
		ft_free_matrix(command_op, paths, 0);
		free(full_path);
	}
	pid = wait(&status);
	if (pid == -1)
		ft_print_perror("wait");
	else
	{
		if (WIFEXITED(status))
			ft_mes_error("Error. Child process end with unexpected result.");
	}
}

int	main(int ac, char *av[])
{
	size_t	i;
	char	**command_op;
	char	**paths;
	int		fd_pipe[2];
	int		fd_outfile;
	pid_t	pid;
	char	*full_path;

	if (ac < 5)
		return (ft_mes_error("Error. Insufficient number of arguments.\n"));
	i = 2;
	if (pipe(fd_pipe) == -1)
	{
		ft_print_perror("pipe");
		return (-1);
	}
	//file to first pipe
	ft_infile_pipefirst(**av, fd_pipe, pid);
	while (i < (ac - 1))
	{
		command_op = ft_split(av[i], ' ');
		if (command_op == NULL)
			return (ft_mes_error("Error. Fail allocate memory.\n"));
printmatrix(command_op, "command and options");
		paths = ft_search_envpaths();
		if (paths == NULL)
			return (ft_free_matrix(command_op, NULL, 1));
printmatrix(paths, "PATHs of env");
		full_path = ft_get_absolute_path(paths, command_op[0]);
		if (full_path == NULL)
			return (ft_free_matrix(command_op, NULL, 0));
printf("path : %s\n", full_path);
		// if(ft_exec_command(full_path, paths, av[1]) == -1)
		// 	return (-1);
		ft_free_matrix(command_op, paths, 0);
		free(full_path);
		i++;
	}
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q a.out");
}