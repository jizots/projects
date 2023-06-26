#include "pipex.h"

static int	ft_make_potential_fullpath(char **matrix_path, char *candidate, char *command, char **fullpath)
{
	char	*temp_path;

	temp_path = ft_strjoin(candidate, "/");
	if (temp_path == NULL)
		return (ft_free_allocates(matrix_path, NULL, NULL, 1));
	*fullpath = ft_strjoin(temp_path, command);
	if (*fullpath == NULL)
		return (ft_free_allocates(matrix_path, NULL, temp_path, 1));
	free(temp_path);
	return (EXIT_SUCCESS);
}

int	ft_get_absolute_path(char **matrix_path, char *command, char **fullpath)
{
	size_t	i;
	char	*s_error;

	i = 0;
	while (matrix_path[i] != NULL)
	{
		if (command[0] == '/')
		{
			*fullpath = ft_strdup(command);
			return (EXIT_SUCCESS);
		}
		if (ft_make_potential_fullpath(matrix_path, matrix_path[i++], command, fullpath) != 0)
			return (EXIT_FAILURE);
		if (access(*fullpath, X_OK) == 0)
			return (EXIT_SUCCESS);
		else if (errno == EACCES)
			ft_print_perror(command);
		free(*fullpath);
	}
	s_error = ft_strjoin(command, " : command not found\n");
	ft_mes_error(s_error);
	return (ft_free_allocates(matrix_path, NULL, s_error, 0));
}
