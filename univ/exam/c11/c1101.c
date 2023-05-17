#include <stdlib.h>
#include <stdio.h>

int ft_copy(int a)
{
    return (a/2);
}

int *ft_map(int *tab, int length, int (*f)(int))
{
    int i;
    int *map;

    map = malloc(sizeof(int) * length);
    if (map == NULL)
        return (map);
    while (i < length)
    {
        map[i] = (*f)(tab[i]);
        i++;
    }
    return (map);
}

int main(void)
{
    int *map;
    int tab[]={42, 21, 3, 0, -5};

    map = ft_map(tab, 5, &ft_copy);
    for (int i=0; i<5; i++)
        printf("%d ",map[i]);
    return (0);
}