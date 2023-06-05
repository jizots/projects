#include "get_next_line.h"

char	*ft_strjoin_to_newline(char *flag, char *buffer, char **str_save, int bytes_read)
{
	size_t	i_delimiter;
	char	*newline;
	char	*str_temp;

	str_temp = *str_save;
	if (bytes_read == 0)
	{
		buffer = *str_save;
		i_delimiter = flag - &buffer[0];
		newline = (char *) ft_calloc((i_delimiter + 1) + 1, sizeof(char));
		if (newline == NULL)
			return (NULL);
		ft_strlcat(newline, buffer, (i_delimiter + 1) + 1);
	}
	else
	{
		i_delimiter = flag - &buffer[0];
		newline = (char *) ft_calloc(ft_strlen(str_temp) + (i_delimiter + 1) + 1, sizeof(char));
		if (newline == NULL)
			return (NULL);
		ft_strlcat(newline, str_temp, ft_strlen(str_temp) + 1);
		ft_strlcat(newline, buffer, ft_strlen(str_temp) + (i_delimiter + 1) + 1);
	}
	*str_save = (char *) ft_calloc(ft_strlen(&buffer[i_delimiter + 1]) + 1, sizeof(char));
	if (*str_save == NULL)
		return (NULL);
	if (ft_strlen(buffer) == (i_delimiter + 1))
		*str_save = NULL;
	else
		ft_strlcat(*str_save, &buffer[i_delimiter + 1], ft_strlen(&buffer[i_delimiter + 1]) + 1);
	free(str_temp);
	return(newline);
}

char	*ft_strjoin_all(char **str_save, int bytes_read, char *buffer)
{
	char	*newline;

	if (bytes_read == 0)
		return (*str_save);
	newline = (char *) ft_calloc((ft_strlen(*str_save) + bytes_read + 1), sizeof(char));
	if (newline == NULL)
		return (NULL);
	ft_strlcat(newline, *str_save, ft_strlen(*str_save) + 1);
	ft_strlcat(newline, buffer, (ft_strlen(*str_save) + bytes_read + 1));
	free(*str_save);
	return (newline);
}

char	*ft_delimicheck_and_branch(char *buffer, const int bytes_read, char **str_save)
{
	char	*flag;
	char	*newline;

	newline = NULL;
	if (bytes_read == 0)
		flag = ft_memchr(*str_save, '\n', ft_strlen(*str_save));
	else
		flag = ft_memchr(buffer, '\n', bytes_read);
	if (flag == NULL)
		*str_save = ft_strjoin_all(str_save, bytes_read, buffer);
	else if (*flag == '\n')
		newline = ft_strjoin_to_newline(flag, buffer, str_save, bytes_read);
	return (newline);
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
		newline = ft_delimicheck_and_branch(buffer, bytes_read, &str_save);
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
		newline = ft_delimicheck_and_branch(buffer, bytes_read, &str_save);
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