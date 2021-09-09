#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	if (str)
	{
		write(1, "Hello world\n", 12);
		ft_putchar_fd('a',1);
	}
	return(0);
}
