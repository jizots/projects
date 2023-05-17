#include <stdio.h>

int ft_modori(char *a)
{
    int i;

    i = 0;
    while (a[i])
    {
        if (a[i++] == '4')
            return (1);
    }
    return (0);
}

int ft_count(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

int ft_any(char **tab, int (*f)(char*))
{
    int length;
    int i;

    length = ft_count(tab);
    i = 0;
    while (i < length)
    {
        if ((*f)(tab[i]))
            return (1);
        i++;
    }
    return (0);
}

int main(void)
{
    char *tab[]={"42","tokyo","is","poww",NULL};
    printf ("%d", ft_any(tab, &ft_modori));
    return (0);
}