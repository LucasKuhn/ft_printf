/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringhandlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:09:26 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/10/11 20:21:43 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_char(va_list args, int *printed_size)
{
	char	c;

	c = va_arg(args, int);
	*printed_size += write(1, &c, 1);
	return ;
}

void	handle_string(va_list args, int *printed_size)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		*printed_size += write(1, "(null)", 6);
		return ;
	}
	*printed_size += write(1, str, ft_strlen(str));
	return ;
}

void	handle_percent(va_list args, int *printed_size)
{
	if (args)
		*printed_size += write(1, "%", 1);
	return ;
}
