#include <stdio.h>
#include <unistd.h>
int power_10(int n, int i)
{
    if (i == 0)
        return (0);
    while(--i)
        n =n * 10;
    return (n);
}

int set_first(int n) {
    int result;
    int i;

    result = 0;
    i = 0;
    while (i < n)
    {
        result = result * 10 + i;
        i++;
    }
    return result;
}

int set_max(int n)
{
    int max;
    int i;

    i = 0;
    max = 9;
    while (i < n)
    {
        max = (9 - i) * (power_10(10, i)) + max;
        i++;
    }
    return (max);
}

int check(int a)
{
    int temp;

    temp = a;
    while (temp > 9)
    {
        if ((temp % 10) <= ((temp / 10) % 10))
            return (-1);
        temp = temp / 10;
    }
    return (1);
}

void    printint(int a)
{
    char c;
    
    if (a >= 10)
    {
        printint(a / 10);
    }
    c = (a % 10) + '0';
    write(1, &c, 1);
}

void    ft_combn(int n)
{
    int first;
    int max;

    first = set_first(n);
    max = set_max(n);
    while (first <= max)
    {
       if (check(first) == 1)
        {
            if (first / power_10(10, n-1) == 0)
                write(1, "0", 1);
            printint(first);
            if (first != max)
               write(1, ", ", 2);
            first++;
        }
        else
            first++;
    }
}

int main(void)
{
    ft_combn(5);
    return 0;
}