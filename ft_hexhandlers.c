/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexhandlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:09:30 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/10/11 17:56:34 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_in_lower_hex(unsigned long int number, int *printed_size);
static void	print_in_upper_hex(unsigned long int number, int *printed_size);

void	handle_lower_hex(va_list args, int *printed_size)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	print_in_lower_hex(i, printed_size);
	return ;
}

void	handle_upper_hex(va_list args, int *printed_size)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	print_in_upper_hex(i, printed_size);
	return ;
}

void	handle_pointer(va_list args, int *printed_size)
{
	void	*pointer;

	*printed_size += write(1, "0x", 2);
	pointer = va_arg(args, void *);
	print_in_lower_hex((unsigned long)pointer, printed_size);
	return ;
}

static void	print_in_lower_hex(unsigned long int number, int *printed_size)
{
	char	*base;

	base = "0123456789abcdef";
	if (number < 16)
	{
		*printed_size += write(1, (base + number), 1);
	}
	else
	{
		print_in_lower_hex(number / 16, printed_size);
		print_in_lower_hex(number % 16, printed_size);
	}
}

static void	print_in_upper_hex(unsigned long int number, int *printed_size)
{
	char	*base;

	base = "0123456789ABCDEFG";
	if (number < 16)
	{
		*printed_size += write(1, (base + number), 1);
	}
	else
	{
		print_in_upper_hex(number / 16, printed_size);
		print_in_upper_hex(number % 16, printed_size);
	}
}
