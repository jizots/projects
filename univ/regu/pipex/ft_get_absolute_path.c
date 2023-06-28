/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_absolute_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:50:26 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/28 14:56:50 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_make_potential_fullpath(char **matrix_path, char *candidate,
	char *command, char **fullpath)
{
	char	*temp_path;

	temp_path = ft_strjoin(candidate, "/");
	if (temp_path == NULL)
		return (ft_free_allocates(matrix_path, NULL, NULL, 1));
	if (command[0] == '/')
		*fullpath = ft_strdup(command);
	else
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
		if (ft_make_potential_fullpath
			(matrix_path, matrix_path[i++], command, fullpath) != 0)
			return (EXIT_FAILURE);
		if (access(*fullpath, X_OK) == 0)
			return (EXIT_SUCCESS);
		else if (errno == EACCES)
			ft_print_perror(command);
		free(*fullpath);
	}
	s_error = ft_strjoin(command, " : command not found\n");
	ft_mes_error(s_error);
	free(s_error);
	*fullpath = ft_strdup(command);
	return (EXIT_SUCCESS);
}
