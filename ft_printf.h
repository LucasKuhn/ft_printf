/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:37:57 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/10/06 22:13:48 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	handle_lower_hex(va_list args, int *printed_size);
void	handle_upper_hex(va_list args, int *printed_size);
void	handle_pointer(va_list args, int *printed_size);
void	handle_number(va_list args, int *printed_size);
void	handle_unsigned(va_list args, int *printed_size);
void	handle_char(va_list args, int *printed_size);
void	handle_string(va_list args, int *printed_size);
void	handle_percent(va_list args, int *printed_size);

// Type definition for all handler functions
typedef void	(*t_handler_function)(va_list, int *);

#endif
