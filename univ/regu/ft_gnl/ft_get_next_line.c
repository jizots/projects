/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotanaka <sotanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:55:46 by sotanaka          #+#    #+#             */
/*   Updated: 2023/07/10 19:29:25 by sotanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

static char	*ft_get_buf(char *save, int fd)
{
	char	*buf;
	int		byte_rd;

	buf = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	while (ft_strchr(save, '\n') == NULL && byte_rd != 0)
	{
		byte_rd = read(fd, buf, BUFFER_SIZE);
		if (byte_rd <= 0)
		{
			ft_free(buf, NULL);
			if (byte_rd == 0)
				return (save);
			return (NULL);
		}
		buf[byte_rd] = '\0';
	}
}

char	*ft_gnl(int fd)
{
	static char	*save;
	char		*buf;
	char		*result;

	if (fd < 0)
		return (NULL);
	buf = ft_get_buf(save, fd);
	if (buf == NULL)
		return (ft_free(save, NULL));
	result = ft_get_result(buf);
	if (result == NULL)
		return (ft_free(save, buf));
	save = ft_get_save(buf);
	if (save == NULL)
		return (NULL);
	return (result);
}