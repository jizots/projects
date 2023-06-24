#include "pipex.h"

char	*ft_make_potential_fullpath(char **paths, char *candidate, char *command)
{
	char	*temp_path;
	char	*full_path;

	temp_path = ft_strjoin(candidate, "/");
	if (temp_path == NULL)
	{
		ft_free_matrix(paths, NULL, 1);
		return (NULL);
	}
	full_path = ft_strjoin(temp_path, command);
	if (full_path == NULL)
	{
		ft_free_matrix(paths, NULL, 1);
		free(temp_path);
		return (NULL);
	}
	free(temp_path);
	return (full_path);
}

char	*ft_get_absolute_path(char **paths, char *command)
{
	size_t	i;
	char	*full_path;
	char	*mes_not_found;

	i = 0;
	while (paths[i] != NULL)
	{
		full_path = ft_make_potential_fullpath(paths, paths[i], command);
		if (full_path == NULL)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		else if (errno == EACCES)
		{
			ft_print_perror(command);
			return (NULL);
		}
		free(full_path);
		i++;
	}
	mes_not_found = ft_strjoin(command, " : command not found\n");
	ft_mes_error(mes_not_found);
	free(mes_not_found);
	ft_free_matrix(paths, NULL, 0);
	return (NULL);
}
