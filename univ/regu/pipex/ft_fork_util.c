/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:49:56 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/01 12:52:16 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*At a line28, i havent good idea for 'how to handle error'.
 Becase bash return no error mes, when exec end with error.*/
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
			;
		return (EXIT_SUCCESS);
	}
}
