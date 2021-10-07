/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringhandlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:09:26 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/10/06 22:09:27 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list args, int *printed_size)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	*printed_size += 1;
	return ;
}

void	handle_string(va_list args, int *printed_size)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*printed_size += 6;
		return ;
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	*printed_size += len;
	return ;
}

void	handle_percent(va_list args, int *printed_size)
{
	if (args)
		*printed_size += 1;
	write(1, "%", 1);
	return ;
}
