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

static char *ft_get_save(char *save)
{
	char	*tmp;
	char	*p_nwl;
	char	*p_nul;

	p_nwl = ft_strchr(save, '\n');
	p_nul = ft_strchr(save, '\0');
	tmp = save;
	if (p_nwl < p_nul && p_nwl != NULL)
	{
		save = malloc (sizeof(char) * (p_nul - p_nwl));
		if (save == NULL)
			return (NULL);
		save[0] = '\0';
		ft_strlcat(save, (p_nwl + 1), (p_nul - p_nwl));
		free(tmp);
	}
	else
	{
		free (save);
		save = NULL;
	}
	return (save);

}

static char	*ft_get_result(char *save)
{
	char	*result;
	char	*p_nwl;
	char	*p_nul;

	p_nwl = ft_strchr(save, '\n');
	p_nul = ft_strchr(save, '\0');
	if (p_nwl < p_nul && p_nwl != NULL)
	{
		result = malloc (sizeof(char) * (p_nwl - save + 1 + 1));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		ft_strlcat(result, save, ((p_nwl - save + 1 + 1)));
	}
	else
		result = save;
	return (result);
}

static char	*ft_read_file(char *save, int fd, char *buf, int byte_rd)
{
	char	*tmp;

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
			ft_free(save, NULL);
			save = NULL;
			return (NULL);
		}
		buf[byte_rd] = '\0';
		tmp = save;
		save = ft_strjoin(tmp, buf);
		if (save == NULL)
			return (ft_free(tmp, buf));
		ft_free(tmp, NULL);
	}
	return (save);
}

char	*ft_gnl(int fd)
{
	static char	*save;
	char		*buf;
	char		*result;
	int			byte_rd;

	if (fd < 0)
		return (NULL);
	buf = NULL;
	byte_rd = 1;
	save = ft_read_file(save, fd, buf, byte_rd);
	if (save == NULL)
		return (NULL);
	result = ft_get_result(save);
	if (result == NULL)
		return (ft_free(save, NULL));
	save = ft_get_save(save);
	if (save == NULL)
		return (ft_free(result, NULL));
	return (result);
}

// int main()
// {
// 	char *line;
// 	int fd;

// 	fd = open("tmp", O_RDONLY);
// 	printf("fd : %d\n", fd);
// 	while (1)
// 	{
// 		line = ft_gnl(fd);
// 		if (line == NULL)
// 			break ;
// 		printf ("result->%s<-\n", line);
// 		free(line);
// 	}

// }
