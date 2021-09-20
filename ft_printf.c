#include "ft_printf.h"

# include <stdio.h>

int	is_type_identifier(char c)
{
	if (ft_strchr("cspdiuxX", c))
		return (1);
	return (0);
}

int	handle_char(va_list args, int *printed_size)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	*printed_size += 1;
	return (1);
}

int	handle_string(va_list args, int *printed_size)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	*printed_size += len;
	write(1, str, sizeof(*str) * len);
	return (1); // Return the size of %s, since there is no flags it is 1
}

void print_in_hex(int number, int *printed_size)
{
	char  *base;
	base = "0123456789abcdef";

	if (number < 16)
	{
		write(1, (base + number), 1);
		printed_size++;
	}
	else
	{
		print_in_hex(number / 16, printed_size);
		print_in_hex(number % 16, printed_size);
	}
}

int	handle_pointer(va_list args, int *printed_size)
{
	char				*str;
	unsigned int		p;

	write(1, "0x10", 4);
	printed_size += 2;
	str = va_arg(args, char *);
	p = (unsigned long)str;
	print_in_hex(p, printed_size);
	return (1);
}

t_handler_function get_type_handler_function(char type)
{
	t_lookup_table table[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'p', handle_pointer},
		{0, 0}
	};
	t_lookup_table *cursor = table;

	while (cursor->type) {
		if (cursor->type == type)
			return (cursor->function);
		cursor++;
	}
	return (0);
}

int interpolate_placeholder(const char *str, va_list args, int *printed_size)
{
	t_handler_function handler_function;
	handler_function = get_type_handler_function(*str);
	return (handler_function(args, printed_size));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	int	printed_size;

	printed_size = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			str += interpolate_placeholder(str, args, &printed_size);
		}
		else
		{
			ft_putchar_fd(*str++, 1);
			printed_size++;
		}
	}
	va_end(args);
	return(printed_size);
}
