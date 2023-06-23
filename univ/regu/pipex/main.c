#include "pipex.h"

void	printmatrix(char **matrix, char *name_item)
{
	printf ("-->%s<--\n", name_item);
	for (int i = 0; matrix[i] != NULL; i++)
		printf("%s\n", matrix[i]);
}

int	main(int ac, char *av[])
{
	size_t	i;
	char	**command_op;
	char	**paths;
	char	*full_path;

	if (ac < 5)
		return (ft_mes_error("Error. Insufficient number of arguments.\n"));
	i = 2;
	while (i < (ac - 1))
	{
		command_op = ft_split(av[i], ' ');
		if (command_op == NULL)
			return (ft_mes_error("Error. Fail allocate memory.\n"));
printmatrix(command_op, "command and options");
		paths = ft_search_envpaths();
		if (paths == NULL)
			return (ft_free_matrix(command_op, 1));
printmatrix(paths, "PATHs of env");
		full_path = ft_get_absolute_path(paths, command_op[0]);
		if (full_path == NULL)
			return (ft_free_matrix(command_op, 0));
printf("path : %s\n", full_path);
		// if(ft_exec_command(full_path, paths, av[1]) == -1)
		// 	return (-1);
		ft_free_matrix(command_op, 0);
		ft_free_matrix(paths, 0);
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