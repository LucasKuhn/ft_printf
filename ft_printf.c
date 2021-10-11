/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:09:40 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/10/11 17:39:30 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_handler_function	get_type_handler_function(char type)
{
	if (type == 'c')
		return (handle_char);
	if (type == 's')
		return (handle_string);
	if (type == 'p')
		return (handle_pointer);
	if (type == 'd')
		return (handle_number);
	if (type == 'i')
		return (handle_number);
	if (type == 'u')
		return (handle_unsigned);
	if (type == 'x')
		return (handle_lower_hex);
	if (type == 'X')
		return (handle_upper_hex);
	if (type == '%')
		return (handle_percent);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list				args;
	int					printed_size;
	t_handler_function	handler_function;

	va_start(args, str);
	printed_size = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			handler_function = get_type_handler_function(*str);
			handler_function(args, &printed_size);
		}
		else
			printed_size += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (printed_size);
}
