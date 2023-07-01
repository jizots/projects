/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:24:22 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/30 19:37:02 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_init_data(t_cmds *data, int ac, char *av[], char *envp[])
{
	data->ac = ac;
	data->av = av;
	data->matrix_env = envp;
	if (ft_search_envpaths(&(data->matrix_epath)) == NULL)
		return (ft_mes_error("envp"));
	if (ft_strstr("here_doc", av[1]) != NULL)
		data->delim = HERE_DOC;
	else
		data->delim = -1;
	data->matrix_cmd = NULL;
	data->path_cmd = NULL;
	if (pipe(data->in_pipefd) == -1)
		return (ft_mes_error("pipe"));
	data->fd_stdin = -1;
	data->fd_stdout = -1;
	return (EXIT_SUCCESS);
}
