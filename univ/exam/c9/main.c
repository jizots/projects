#include "ft1.h"

int main(void)
{
    ft_putdouble(1.1111, 5);
    puts("double");
    ft_atoi_base("8", "01");
    puts("atoi_base");
    printf("%d", power_10(10));
    puts("power_10");
    printf("%zu", ft_strlen("123456"));
    puts("strlen");
    return (0);
}

//cc main.c ft.a -o a.out