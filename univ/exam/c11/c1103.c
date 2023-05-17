#include <stdio.h>

int ft_modori(char *a)
{
    int i;

    i = 0;
    while (a[i])
    {
        if (a[i++] == 'w')
            return (1);
    }
    return (0);
}

int ft_count_if(char **tab, int length, int (*f)(char*))
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (i < length)
    {
        if ((*f)(tab[i++]))
            count++;
    }
    return (count);
}

int main(void)
{
    char *tab[]={"42","tokyo","is","poww",NULL};
    printf ("%d", ft_count_if(tab, 4, &ft_modori));
    return (0);
}