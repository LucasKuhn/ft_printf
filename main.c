/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalexk-ku <lalex-ku@42sp.org.br>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:11:47 by lalexk-ku         #+#    #+#             */
/*   Updated: 2021/10/11 18:11:48 by lalexk-ku        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

typedef int		(*printf_alias)(const char *, ...);
printf_alias	og_printf = printf;

// %[parameter][flags][width][.precision][length]type
// cspdiuxX%
// ’-0.’
// ’# +’

int	main()
{
	char	*str;

	str = "Bonjour";
	og_printf("og | Char		->(%c)\n", 'A');
	ft_printf("42 | Char		->(%c)\n", 'A');
	og_printf("og | String		->(%s)\n", str);
	ft_printf("42 | String		->(%s)\n", str);
	og_printf("og | String null	->(%s)\n", NULL);
	ft_printf("42 | String null	->(%s)\n", NULL);
	og_printf("og | Pointer		->(%p)\n", str);
	ft_printf("42 | Pointer		->(%p)\n", str);
	og_printf("og | Pointer		->(%p)\n", 1);
	ft_printf("42 | Pointer		->(%p)\n", 1);
	og_printf("og | Pointer		->(%p)\n", -1);
	ft_printf("42 | Pointer		->(%p)\n", -1);
	og_printf("og | Decimal		->(%d)\n", 123);
	ft_printf("42 | Decimal		->(%d)\n", 123);
	og_printf("og | Integer		->(%i)\n", 42);
	ft_printf("42 | Integer		->(%i)\n", 42);
	og_printf("og | Unsigned  Int	->(%u)\n", -42);
	ft_printf("42 | Unsigned  Int	->(%u)\n", -42);
	og_printf("og | Lowercase Hex	->(%x)\n", -9);
	ft_printf("ft | Lowercase Hex	->(%x)\n", -9);
	og_printf("og | Lowercase Hex	->(%x)\n", 9223372036854775807L);
	ft_printf("ft | Lowercase Hex	->(%x)\n", 9223372036854775807L);
	og_printf("og | Uppercase Hex	->(%X)\n", -1);
	ft_printf("ft | Uppercase Hex	->(%X)\n", -1);
	og_printf("og | Uppercase Hex	->(%X)\n", 15);
	ft_printf("ft | Uppercase Hex	->(%X)\n", 15);
	og_printf("og | Percent sign 	->(%%)\n", 42);
	ft_printf("ft | Percent sign 	->(%%)\n", 42);
	printf("\n~~ RETURN CHECK ~~\n");
	write(1, "og | ", 5);
	printf(" ->(%d)\n", og_printf("Oui%c", '!'));
	write(1, "42 | ", 5);
	printf(" ->(%d)\n", ft_printf("Oui%c", '!'));
	write(1, "og | ", 5);
	printf(" ->(%d)\n", og_printf("%i", 443322));
	write(1, "42 | ", 5);
	printf(" ->(%d)\n", ft_printf("%i", 443322));
}
