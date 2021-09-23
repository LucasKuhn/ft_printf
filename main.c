#include "ft_printf.h"

# include <stdio.h>

typedef int (*printf_alias)(const char * , ...);
printf_alias og_printf = printf;

// %[parameter][flags][width][.precision][length]type
// cspdiuxX%
// ’-0.’
// ’# +’

int main()
{
	char *str = "Bonjour";
	og_printf("og | Char	->(%c)\n", 'A');
	ft_printf("42 | Char	->(%c)\n", 'A');
	og_printf("og | String	->(%s)\n", str);
	ft_printf("42 | String	->(%s)\n", str);
	og_printf("og | Pointer	->(%p)\n", str);
	ft_printf("42 | Pointer	->(%p)\n", str);
	og_printf("og | Decimal	->(%d)\n", 123);
	ft_printf("42 | Decimal	->(%d)\n", 123);
	og_printf("og | Integer	->(%i)\n", 42);
	ft_printf("42 | Integer	->(%i)\n", 42);
	og_printf("og | U Int	->(%u)\n", -42);
	ft_printf("42 | U Int	->(%u)\n", -42);
	og_printf("og | Low Hex	->(%x)\n", 123);
	ft_printf("ft | Low Hex	->(%x)\n", 123);
	og_printf("og | Up Hex	->(%X)\n", 123);
	ft_printf("ft | Up Hex	->(%X)\n", 123);
	og_printf("og | Percent	->(%%)\n", 42);
	ft_printf("ft | Percent	->(%%)\n", 42);

	// ft_printf("ft | Char ->(%0c)\n", 'a');
	// og_printf("Int      ->(% i) (%   i)\n", 123, 998);

	printf("\n~~ RETURN CHECK ~~\n");
	write(1,"og | ",5);
	printf(" ->(%d)\n", og_printf("Oui%c",'!'));
	write(1,"42 | ",5);
	printf(" ->(%d)\n", ft_printf("Oui%c",'!'));

}
