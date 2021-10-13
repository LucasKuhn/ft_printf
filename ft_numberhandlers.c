/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberhandlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:09:33 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/10/12 20:12:25 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*uitoa(unsigned int n);
static int	digits_in_number(unsigned int n);

void	handle_number(va_list args, int *printed_size)
{
	int		i;
	char	*str;

	i = va_arg(args, int);
	str = ft_itoa(i);
	*printed_size += write(1, str, ft_strlen(str));
	free(str);
	return ;
}

void	handle_unsigned(va_list args, int *printed_size)
{
	unsigned int	i;
	char			*str;

	i = va_arg(args, unsigned int);
	str = uitoa(i);
	*printed_size += write(1, str, ft_strlen(str));
	free(str);
	return ;
}

static int	digits_in_number(unsigned int n)
{
	if (n / 10 == 0)
		return (1);
	return (1 + digits_in_number(n / 10));
}

static char	*uitoa(unsigned int n)
{
	char	*str;
	int		digits;

	digits = digits_in_number(n);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
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
