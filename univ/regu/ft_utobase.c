#include "printf.h"

void    input_hexadecimal(unsigned int n, char *base, char *p_result, unsigned char len_result)
{
	unsigned char	len_base;
	int				i;

	len_base = (unsigned char)ft_strlen(base);
	i = 0;
	while (n != 0)
	{
		p_result[len_result - 1 - i] = base[n % len_base];
		n = n / len_base;
		i++;
	}
}

char	*ft_utobase(unsigned int n, char *base)
{
	unsigned char	len_base;
	unsigned char	len_result;
	char			*p_result;
	unsigned int	temp_n;

	if (base == NULL || base[0] == '\0' || ft_str_only_chr(base) == -1)
	{
		write(1, "base error", 10);
		return (NULL);
	}
	temp_n = n;
	len_base = (unsigned char)ft_strlen(base);
	len_result = 0;
	while (temp_n != 0)
	{
		temp_n = temp_n / len_base;
		len_result++;
	}
	p_result = ft_calloc(sizeof(char), (len_result + 1));
	if (p_result == NULL)
		return (NULL);
	input_hexadecimal(n, base, p_result, len_result);
	return (p_result);
}

// int main()
// {
//     char    base[]="0123456789";
//     unsigned int     nbr = 0;
// 	char *p;

// 	p = ft_utobase(nbr, "0123456789");
//     printf ("my   %s\n", p);
// 	free(p);

//     printf ("std  %x\n", nbr);

// 	p = ft_utobase(nbr, "0123456789abcdef");
//     printf ("myx  %s\n", p);
// 	free(p);

// 	p = ft_utobase(nbr, "0123456789ABCDEF");
//     printf ("myX  %s\n", p);
// 	free(p);
//     return (0);
// }