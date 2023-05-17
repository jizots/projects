#include <stdio.h>

int ft_is_prime(int nb)
{
    unsigned i;
    unsigned na;
    if(nb < 2)
        return (0);
    if(nb == 2)
        return (1);
    if(nb % 2 == 0)
        return (0);
    na = (unsigned)nb;
    i = 3;
    while (nb > (i * i))
    {
        if (nb % i == 0)
            return (0);
        i += 2;
    }
    return (1);
}

int main(void)
{
    printf("1:%d\n", ft_is_prime(3));
    printf("1:%d\n", ft_is_prime(5));
    printf("1:%d\n", ft_is_prime(7));
    printf("1:%d\n", ft_is_prime(11));
    printf("1:%d\n", ft_is_prime(2147483647));
    printf("0:%d\n", ft_is_prime(4));
    printf("0:%d\n", ft_is_prime(15));
    printf("0:%d\n", ft_is_prime(21));
}