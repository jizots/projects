#include <stdio.h>
int	ft_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	ft_swap(char **a, char **b)
{
	char *temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort(char **tab, int (*cmp)(char *, char *))
{
	int	lentab;
	int	i;
	int	j;

	lentab = ft_len(tab);
	i = 0;
	while (i < lentab - 1)
	{
		j = i + 1;
		while (j < lentab)
		{
			if ((*cmp)(tab[i], tab[j]) > 0)
				ft_swap (&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

int main(void)
{
	char *av[] = {"3", "1","ii", "22", "2", NULL};
	ft_advanced_sort(av, &ft_strcmp);
	for (int i=0; i<5; i++)
		printf ("%s\n", av[i]);
}