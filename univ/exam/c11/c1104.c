#include <stdio.h>

int ft_compi(int a, int b)
{
    if (a < b)
        return (-1);
    else if (a == b)
        return (0);
    else
        return (1);
}

int ft_is_sort(int *tab, int length, int (*f)(int, int))
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (i + 1 < length)
    {
        if ((*f)(tab[i], tab[i + 1]) != 0)
        {
            if (flag != (*f)(tab[i], tab[i + 1]) && flag != 0)
                return (0);
            flag = (*f)(tab[i], tab[i + 1]);
        }
		i++;
    }
	return (1);
}

int main(void)
{
    int tab[]={6,2,2,2,1,2};
    printf("%d", ft_is_sort(tab, 6, &ft_compi));
    return (0);
}