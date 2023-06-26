#include "pipex.h"

char	*ft_make_potential_fullpath(char **matrix_path, char *candidate, char *command)
{
	char	*temp_path;
	char	*fullpath;

	temp_path = ft_strjoin(candidate, "/");
	if (temp_path == NULL)
	{
		ft_free_allocates(matrix_path, NULL, NULL, 1);
		return (NULL);
	}
	fullpath = ft_strjoin(temp_path, command);
	if (fullpath == NULL)
	{
		ft_free_allocates(matrix_path, NULL, NULL, 1);
		free(temp_path);
		return (NULL);
	}
	free(temp_path);
	return (fullpath);
}

char	*ft_get_absolute_path(char **matrix_path, char *command, char **fullpath)
{
	size_t	i;
	char	*s_error;

	i = 0;
	while (matrix_path[i] != NULL)
	{
		*fullpath = ft_make_potential_fullpath(matrix_path, matrix_path[i], command);
		if (*fullpath == NULL)
			return (NULL);
		if (access(*fullpath, X_OK) == 0)
			return (*fullpath);
		else if (errno == EACCES)
		{
			ft_print_perror(command);
			return (NULL);
		}
		free(*fullpath);
		i++;
	}
	s_error = ft_strjoin(command, " : command not found.\n");
	ft_mes_error(s_error);
	free(s_error);
	ft_free_allocates(matrix_path, NULL, NULL, 0);
	return (NULL);
}
