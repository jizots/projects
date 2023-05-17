#include <stdio.h>
#include <stdlib.h>


int ft_strlen(char *src)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (src[i++])
        count++;
    return (count);
}

int c_cmp(char object, char *sep, int seplen)
{
    int i;

    i = 0;
	seplen = ft_strlen(sep);
    while (i < seplen)
    {
        if (object == sep[i++])
            return (-1);
    }
    return (1);
}

void    len_array(char *str, char *sep, int *lenarray)
{
    int flag;
    int i;
    int seplen;

    seplen = ft_strlen(sep);
    flag = -1;
    i = 0;
    while (str[i])
    {
		if (c_cmp(str[i], sep, seplen) == 1 && flag == -1)
		{
			(*lenarray)++;
			flag = 1;
		}
		else if (c_cmp(str[i], sep, seplen) == -1)
			flag = -1;
		else if(c_cmp(str[i], sep, seplen) == 1 && flag == 1)
			;
		i++;
    }
}

void	input(char **boxs, char *str, char *sep, int *lenarray)
{
	int	i;
	int	j;
	int	flag;
	int row, column;
	int seplen = ft_strlen(sep);

	i = 0;
	j = 0;
	flag = -1;
	row = 0;
	while (row < *lenarray)
	{
		column = 0;
		while (str[i])
		{
			if (c_cmp(str[i], sep, seplen) == 1 && flag == -1)
				flag = 1;
			else if (c_cmp(str[i], sep, seplen) == -1 && flag == 1)
			{
				flag = -1;
				break ;
			}
			if(c_cmp(str[i], sep, seplen) == 1 && flag == 1)
			{
				boxs[row][column++] = str[i];
				boxs[row][column] = '\0';
			}
			i++;
		}
		row++;
	}
}

char    **box(char *str, char *sep, int *lenarray)
{
    char **boxs;

	len_array(str, sep, lenarray);
    boxs = malloc (sizeof(char *) * (*lenarray + 1));
	if (boxs  == NULL)
		return (boxs);
	boxs[*lenarray] = NULL;
	int i = 0;
	while (i < *lenarray)
	{
		boxs[i] = malloc (sizeof(char) * 1024);
		if (boxs[i++] == NULL)
			return (boxs = NULL);
	}
	input(boxs, str, sep , lenarray);

	return (boxs);
}

int main(void)
{
    char    str[]="  vriaanovirj\n, jram  vtmv490  ";
    char    sep[]=" a.out";
    char    **boxs;
    int     lenarray;

	lenarray = 0;
    boxs = box(str, sep, &lenarray);
    for (int i = 0; i < lenarray; i++)
    {
        printf("box[%d]%s\n", i, boxs[i]);
    }
    int i = 0;
	while(lenarray--)
	{
		free(boxs[i++]);
	}
	free(boxs);
    return 0;
}