#include <unistd.h>
#include <stdio.h>

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

void    put_hexadecimal(long long nbl, char *base, int hexlen)
{
    int c;
    if (nbl >= hexlen)
    {
        put_hexadecimal(nbl / hexlen, base, hexlen);
    }
    c = nbl % hexlen;
    write (1, &base[c], 1);
}

void    ft_putnbr_base(int nbr, char *base)
{
    int			hexlen;
    long long	nbl;

    hexlen = ft_strlen(base);
    if (nbr < 0)
    {
        write(1, "-", 1);
        nbl = (long long)nbr;
		nbl = -nbl;
        put_hexadecimal(nbl, base, hexlen);
    }
    else 
    {
        nbl = nbr;
        put_hexadecimal(nbl, base, hexlen);
    }
}

int main()
{
    char    base[]="poneyvif";
    int     nbr = 31;

    ft_putnbr_base(nbr, base);
    return (0);
}