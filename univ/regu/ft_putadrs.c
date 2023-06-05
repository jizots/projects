#include "printf.h"

void	ft_putadrs(uintptr_t address)
{
	ft_putstr("0x");
	ft_puthex(address, 0);
}
