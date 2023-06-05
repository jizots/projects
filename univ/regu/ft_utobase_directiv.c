#include "printf.h"

size_t	ft_utobase_directiv(unsigned int n, t_directiv *direct)
{
	size_t	len_puts;
	char	*p_numstr;

	(void)direct;
	len_puts = 0;
	if (direct->conv_spec == 'u')
		p_numstr = ft_utobase(n, "0123456789");
	else if (direct->conv_spec == 'x')
		p_numstr = ft_utobase(n, "0123456789abcdef");
	else if (direct->conv_spec == 'X')
		p_numstr = ft_utobase(n, "0123456789ABCDEF");
	if (ft_putstr(p_numstr) == -1)
	{
		write (1, "allocated string is NULL", 24);
		return (0);
	}
	len_puts = ft_strlen(p_numstr);
	free(p_numstr);
	return (len_puts);
}