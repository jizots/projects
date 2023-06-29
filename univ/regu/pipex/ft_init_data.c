/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:24:22 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/29 19:27:26 by sotanaka         ###   ########.fr       */
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
	data->delim = 0;
	data->matrix_cmd = NULL;
	data->path_cmd = NULL;
	if (pipe(data->in_pipefd) == -1)
		return(ft_mes_error("pipe"));
	return (EXIT_SUCCESS);
}