/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_absolute_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:50:26 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/30 19:36:22 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_make_potential_fullpath(t_cmds *data, char *candidate)
{
	char	*temp_path;

	temp_path = ft_strjoin(candidate, "/");
	if (temp_path == NULL)
		return (ft_free_allocates(data->matrix_epath, NULL, NULL, 1));
	if (data->matrix_cmd[0][0] == '/')
		data->path_cmd = ft_strdup(data->matrix_cmd[0]);
	else
		data->path_cmd = ft_strjoin(temp_path, data->matrix_cmd[0]);
	if (data->path_cmd == NULL)
		return (ft_free_allocates(data->matrix_epath, NULL, temp_path, 1));
	free(temp_path);
	return (EXIT_SUCCESS);
}

int	ft_get_absolute_path(t_cmds *data)
{
	size_t	i;
	char	*s_error;

	i = 0;
	while (data->matrix_epath[i] != NULL)
	{
		if (ft_make_potential_fullpath(data, data->matrix_epath[i++]) != 0)
			return (EXIT_FAILURE);
		if (access(data->path_cmd, X_OK) == 0)
			return (EXIT_SUCCESS);
		else if (errno == EACCES)
			ft_print_perror(data->matrix_cmd[0]);
		free(data->path_cmd);
	}
	s_error = ft_strjoin(data->matrix_cmd[0], " : command not found\n");
	ft_mes_error(s_error);
	free(s_error);
	data->path_cmd = ft_strdup(data->matrix_cmd[0]);
	return (EXIT_SUCCESS);
}
