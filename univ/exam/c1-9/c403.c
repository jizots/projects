#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int ft_atoi(char *src)
{
    int i;
    int nor;
    int minus;

    i = 0;
    while (src[i] == ' ')
        i++;
    minus = 0;
    while (src[i] == '+' || src[i] == '-')
    {
        if (src[i] == '-')
            minus++;
        i++;
    }
    nor = 0;
    while ('0' <= src[i] && src[i] <= '9')
    {
        nor = nor * 10 + (src[i] - '0');
        i++;
    }
    if (minus % 2 == 0)
        return (nor);
    else
        return (-nor);
}

int main()
{
    char    src[]="-21474836489";
    
    printf("%d\n", ft_atoi(src));
    printf("%d\n", atoi(src));
}