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
	if (!str)
	{
		write(1, "(null)", 6);
		*printed_size += 6;
		return (1);
	}
	len = ft_strlen(str);
	*printed_size += len;
	write(1, str, sizeof(*str) * len);
	return (1); // Return the size of %s, since there is no flags it is 1
}

void print_in_hex(unsigned long int number, int *printed_size)
{
	char  *base;
	base = "0123456789abcdef";

	if (number < 16)
	{
		write(1, (base + number), 1);
		*printed_size += 1;
	}
	else
	{
		print_in_hex(number / 16, printed_size);
		print_in_hex(number % 16, printed_size);
	}
}

void print_in_upper_hex(unsigned long int number, int *printed_size)
{
	char  *base;
	base = "0123456789ABCDEFG";

	if (number < 16)
	{
		write(1, (base + number), 1);
		*printed_size += 1;
	}
	else
	{
		print_in_upper_hex(number / 16, printed_size);
		print_in_upper_hex(number % 16, printed_size);
	}
}

int	handle_pointer(va_list args, int *printed_size)
{
	void	* pointer;

	write(1, "0x", 2);
	*printed_size += 2;
	pointer = va_arg(args, void *);
	print_in_hex((unsigned long) pointer, printed_size);
	return (1);
}

int handle_number(va_list args, int *printed_size)
{
	int i;
	i = va_arg(args, int);
	char *str = ft_itoa(i);
	ft_putstr_fd(str,1);
	*printed_size += ft_strlen(str);
	free(str);
	return(1);
}

static int	digits_in_number(unsigned int n)
{
	if (n < 0 && n / 10 == 0)
		return (2);
	if (n / 10 == 0)
		return (1);
	return (1 + digits_in_number(n / 10));
}

static char		*uitoa(unsigned int n)
{
	char	*str;
	int		digits;

	digits = digits_in_number(n);
	if (!(str = malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	str[digits] = '\0';
	while (n >= 10)
	{
		str[--digits] = '0' + n % 10;
		n = n / 10;
	}
	str[--digits] = '0' + n % 10;
	return (str);
}

int handle_unsigned(va_list args, int *printed_size)
{
	unsigned int i;
	i = va_arg(args, unsigned int);
	char *str = uitoa(i);
	ft_putstr_fd(str,1);
	*printed_size += ft_strlen(str);
	free(str);
	return(1);
}

int handle_lower_hex(va_list args, int *printed_size)
{
	unsigned int i;
	i = va_arg(args, unsigned int);
	print_in_hex(i, printed_size);
	return(1);
}

int handle_upper_hex(va_list args, int *printed_size)
{
	unsigned int i;
	i = va_arg(args, unsigned int);
	print_in_upper_hex(i, printed_size);
	return(1);
}

int handle_percent(va_list args, int *printed_size)
{
	if (args){};
	*printed_size += 1;
	write(1,"%",1);
	return(1);
}

t_handler_function get_type_handler_function(char type)
{
	t_lookup_table table[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'p', handle_pointer},
		{'d', handle_number},
		{'i', handle_number},
		{'u', handle_unsigned},
		{'x', handle_lower_hex},
		{'X', handle_upper_hex},
		{'%', handle_percent},
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
	if (handler_function)
	{
		return (handler_function(args, printed_size));
	}
	else
		return(1);
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
			interpolate_placeholder(str, args, &printed_size);
			str++;
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
