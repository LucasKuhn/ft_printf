/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 21:37:57 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/09/20 15:05:22 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include<stdarg.h>

int	ft_printf(const char *str, ...);

// Generic definition for all handler functions
typedef int (*t_handler_function)(va_list, int *);
// Lookup table to know which function to call based on type
typedef struct s_lookup_table {
	char type;
	t_handler_function function;
} t_lookup_table;

#endif
