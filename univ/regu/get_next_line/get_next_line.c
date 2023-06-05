#include "get_next_line.h"

int	ft_strjoin_to_newline(char *buffer, char **str_save, int bytes_read, char **newline)
{
	char	*flag;
	size_t	i_delimiter;
	char	*str_temp;

	str_temp = *str_save;
	if (bytes_read == 0)
	{
		flag = ft_memchr(*str_save, '\n', ft_strlen(*str_save));
		buffer = *str_save;
		i_delimiter = flag - &buffer[0];
		*newline = (char *) ft_calloc((i_delimiter + 1) + 1, sizeof(char));
		if (*newline == NULL)
			return (-1);
		ft_strlcat(*newline, buffer, (i_delimiter + 1) + 1);
	}
	else
	{
		flag = ft_memchr(buffer, '\n', bytes_read);
		i_delimiter = flag - &buffer[0];
		*newline = (char *) ft_calloc(ft_strlen(str_temp) + (i_delimiter + 1) + 1, sizeof(char));
		if (*newline == NULL)
			return (-1);
		ft_strlcat(*newline, str_temp, ft_strlen(str_temp) + 1);
		ft_strlcat(*newline, buffer, ft_strlen(str_temp) + (i_delimiter + 1) + 1);
	}
	*str_save = (char *) ft_calloc(ft_strlen(&buffer[i_delimiter + 1]) + 1, sizeof(char));
	if (*str_save == NULL)
		return (-1);
	if (ft_strlen(buffer) == (i_delimiter + 1))
		*str_save = NULL;
	else
		ft_strlcat(*str_save, &buffer[i_delimiter + 1], ft_strlen(&buffer[i_delimiter + 1]) + 1);
	free(str_temp);
	return (0);
}

int	ft_strjoin_all(char **str_save, int bytes_read, char *buffer)
{
	char	*newline;

	if (bytes_read == 0)
		return (0);
	newline = (char *) ft_calloc((ft_strlen(*str_save) + bytes_read + 1), sizeof(char));
	if (newline == NULL)
		return (-1);
	ft_strlcat(newline, *str_save, ft_strlen(*str_save) + 1);
	ft_strlcat(newline, buffer, (ft_strlen(*str_save) + bytes_read + 1));
	free(*str_save);
	*str_save = newline;
	return (0);
}

int	ft_createline_nobuffer(char **str_save, char **newline, char *flag)
{
	size_t	i_delimiter;
	char	*str_temp;

	if (flag == NULL)
		return (0);
	str_temp = *str_save;
	flag = ft_memchr(str_temp, '\n', ft_strlen(*str_save));
	i_delimiter = flag - &str_temp[0];
	*newline = (char *) ft_calloc((i_delimiter + 1) + 1, sizeof(char));
	if (*newline == NULL)
		return (-1);
	ft_strlcat(*newline, str_temp, (i_delimiter + 1) + 1);
	if (ft_strlen(str_temp) == (i_delimiter + 1))
	{
		free(str_save);
		*str_save = NULL;
		return (0);
	}
	*str_save = (char *) ft_calloc(ft_strlen(&str_temp[i_delimiter + 1]) + 1, sizeof(char));
	if (*str_save == NULL)
		return (-1);
	else
		ft_strlcat(*str_save, &str_temp[i_delimiter + 1], ft_strlen(&str_temp[i_delimiter + 1]) + 1);
	free(str_temp);
	return (0);
}

int	ft_createline_tonewline(char *buffer, char **str_save, const int bytes_read, char **newline)
{
	char	*flag;
	size_t	i_delimiter;
	char	*str_temp;

	str_temp = *str_save;
	flag = ft_memchr(buffer, '\n', bytes_read);
	i_delimiter = flag - &buffer[0];
	*newline = (char *) ft_calloc(ft_strlen(str_temp) + (i_delimiter + 1) + 1, sizeof(char));
	if (*newline == NULL)
		return (-1);
	ft_strlcat(*newline, str_temp, ft_strlen(str_temp) + 1);
	ft_strlcat(*newline, buffer, ft_strlen(str_temp) + (i_delimiter + 1) + 1);
	*str_save = (char *) ft_calloc(ft_strlen(&buffer[i_delimiter + 1]) + 1, sizeof(char));
	if (*str_save == NULL)
		return (-1);
	if (ft_strlen(buffer) == (i_delimiter + 1))
		*str_save = NULL;
	else
		ft_strlcat(*str_save, &buffer[i_delimiter + 1], ft_strlen(&buffer[i_delimiter + 1]) + 1);
	free(str_temp);
	return (0);
}

int	ft_createline_withbuffer(char *buffer, const int bytes_read, char **str_save, char **newline)
{
	char	*flag;
	
	flag = ft_memchr(buffer, '\n', bytes_read);
	if (flag == NULL)
	{
		*newline = (char *) ft_calloc((ft_strlen(*str_save) + bytes_read + 1), sizeof(char));
		if (*newline == NULL)
			return (-1);
		ft_strlcat(*newline, *str_save, ft_strlen(*str_save) + 1);
		ft_strlcat(*newline, buffer, (ft_strlen(*str_save) + bytes_read + 1));
		free(*str_save);
		*str_save = *newline;
	}
	else
	{
		if(ft_createline_tonewline(buffer, str_save, bytes_read, newline) == -1)
			return (-1);
	}
	return (0);
}

int	ft_delimicheck_and_branch(char *buffer, const int bytes_read, char **str_save, char **newline)
{
	char	*flag;

	*newline = NULL;
	if (bytes_read == 0)
	{
		flag = ft_memchr(*str_save, '\n', ft_strlen(*str_save));
		if (ft_createline_nobuffer(str_save, newline, flag) == -1)
		{
			if (str_save != NULL)
				free(str_save);
			return (-1);
		}
	}
	else
	{
		if (ft_createline_withbuffer(buffer, bytes_read, str_save, newline) == -1)
		{
			if (str_save != NULL)
				free(str_save);
			return (-1);
		}		
	}
	// if (flag == NULL)
	// {
	// 	if (ft_strjoin_all(str_save, bytes_read, buffer) == -1)
	// 	{
	// 		if (str_save != NULL)
	// 			free(str_save);
	// 		return (-1);
	// 	}
	// }
	// else if (*flag == '\n')
	// {
	// 	if (ft_strjoin_to_newline(buffer, str_save, bytes_read, newline) == -1)
	// 	{
	// 		if (str_save != NULL)
	// 			free(str_save);
	// 		return (-1);
	// 	}
	// }
	return (0);
}

char	*get_next_line(int fd)
{
	char		*newline;
	static char	*str_save;
	int			bytes_read;
	char		*buffer;

	if (fd == -1 || SIZE_READ < 0)
		return (NULL);
	bytes_read = 0;
	buffer = NULL;
	if (str_save != NULL)
	{
		if (ft_delimicheck_and_branch(buffer, bytes_read, &str_save, &newline) == -1)
			return (NULL);
		if (newline != NULL)
			return (newline);
	}
	buffer = (char *) ft_calloc(SIZE_READ + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		bytes_read = read(fd, buffer, SIZE_READ);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (bytes_read == 0 && str_save != NULL)
			{
				newline = str_save;
				str_save = NULL;
				return (newline);
			}
			return (NULL);
		}
		if (ft_delimicheck_and_branch(buffer, bytes_read, &str_save, &newline) == -1)
			return (NULL);
		if (newline != NULL)
		{
			free(buffer);
			return (newline);
		}
	}
}

int main()
{
	char *line;
	int fd;

	fd = open("files", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf ("result->%s<-\n", line);
		free(line);
	}

}