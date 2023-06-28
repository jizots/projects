/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:56 by sotanaka          #+#    #+#             */
/*   Updated: 2023/06/28 14:55:51 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_wait_judge_child(int pid)
{
	int	status;

	if (pid == -1)
		return (ft_print_perror("fork"));
	else
	{
		pid = wait(&status);
		if (pid == -1)
			return (ft_print_perror("wait"));
		if (WIFEXITED(status) && WEXITSTATUS(status))
			return (ft_mes_error("Child process end with error."));
		return (0);
	}
}
