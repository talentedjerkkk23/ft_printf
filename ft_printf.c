
#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	argp;
	t_fmt *f;
	int len;

	f = (t_fmt*)malloc(sizeof(t_fmt));
	reset_format(f);
	f->total_len = 0;
	va_start(argp, fmt);
	ft_parse_args(fmt, f, argp);
	va_end(argp);
	len = f->total_len;
	free(f);
	return (len);
}





void decimal_checker()
{
	printf("\n<|############################|>\n");

	ft_printf("my: %d|\n", 0);
	printf("og: %d|\n", 0);
	ft_printf("my: %d|\n", -7);
	printf("og: %d|\n", -7);
	ft_printf("my: %d|\n", 1560133635);
	printf("og: %d|\n", 1560133635);
	ft_printf("my: %d|\n", -2035065302);
	printf("og: %d|\n", -2035065302);

	// PLUS
	printf("\n<|############################|>\n");

	ft_printf("my: %+14d|\n", 0);
	printf("og: %+14d|\n", 0);
	ft_printf("my: %+14d|\n", 12);
	printf("og: %+14d|\n", 12);
	ft_printf("my: %+14d|\n", -7);
	printf("og: %+14d|\n", -7);
	ft_printf("my: %+14d|\n", 1560133635);
	printf("og: %+14d|\n", 1560133635);
	ft_printf("my: %+14d|\n", -2035065302);
	printf("og: %+14d|\n", -2035065302);

	// SPACE
	printf("\n<|############################|>\n");

	ft_printf("my: %05d|\n", 0);
	printf("og: %05d|\n", 0);
	ft_printf("my: %05d|\n", -7);
	printf("og: %05d|\n", -7);
	ft_printf("my: %012d|\n", 120);
	printf("og: %012d|\n", 120);
	ft_printf("my: %05d|\n", 1560133635);
	printf("og: %05d|\n", 1560133635);
	ft_printf("my: %05d|\n", -2035065302);
	printf("og: %05d|\n", -2035065302);


	printf("\n<|######--RIGHT  ALIGN--######|>\n");
	// RIGHT ALIGN
	ft_printf("my: %+-5d|\n", 0);
	printf("og: %+-5d|\n", 0);
	ft_printf("my: %+-5d|\n", -7);
	printf("og: %+-5d|\n", -7);
	ft_printf("my: %+-5d|\n", 1560133635);
	printf("og: %+-5d|\n", 1560133635);
	ft_printf("my: %+-5d|\n", -2035065302);
	printf("og: %+-5d|\n", -2035065302);

	printf("\n<|############################|>\n");

	ft_printf("my: %-05d|\n", 0);
	printf("og: %-05d|\n", 0);
	ft_printf("my: %-05d|\n", -7);
	printf("og: %-05d|\n", -7);
	ft_printf("my: %-012d|\n", 120);
	printf("og: %-012d|\n", 120);
	ft_printf("my: %-012d|\n", -120);
	printf("og: %-012d|\n", -120);
	ft_printf("my: %-05d|\n", 1560133635);
	printf("og: %-05d|\n", 1560133635);
	ft_printf("my: %-05d|\n", -2035065302);
	printf("og: %-05d|\n", -2035065302);

	printf("\n<|########--PRECISION--#######|>\n");

	ft_printf("my: %-+.9d|\n", 7);
	printf("og: %-+.9d|\n", 7);
	ft_printf("my: %-+.9d|\n", -7);
	printf("og: %-+.9d|\n", -7);
	ft_printf("my: %-.15d|\n", 722);
	printf("og: %-.15d|\n", 722);;
	ft_printf("my: %+.5d|\n", 7);
	printf("og: %+.5d|\n", 7);
	ft_printf("my: %+.1d|\n", 7);
	printf("og: %+.1d|\n", 7);
	ft_printf("my: %.d|\n", 7);
	printf("og: %.d|\n", 7);
	ft_printf("my: %.-1d|\n", 7);
	printf("og: %.-1d|\n", 7);

	printf("\n<|############################|>\n");
}

void	unsigned_decimal_checker()
{
	printf("\n<|############################|>\n");

	ft_printf("my: %u|\n", 0);
	printf("og: %u|\n", 0);
	ft_printf("my: %u|\n", -7);
	printf("og: %u|\n", -7);
	ft_printf("my: %u|\n", 1560133635);
	printf("og: %u|\n", 1560133635);
	ft_printf("my: %u|\n", -2035065302);
	printf("og: %u|\n", -2035065302);

	// PLUS
	printf("\n<|############################|>\n");

	ft_printf("my: %+14u|\n", 0);
	printf("og: %+14u|\n", 0);
	ft_printf("my: %+14u|\n", 12);
	printf("og: %+14u|\n", 12);
	ft_printf("my: %+14u|\n", -7);
	printf("og: %+14u|\n", -7);
	ft_printf("my: %+14u|\n", 1560133635);
	printf("og: %+14u|\n", 1560133635);
	ft_printf("my: %+14u|\n", -2035065302);
	printf("og: %+14u|\n", -2035065302);

	// SPACE
	printf("\n<|############################|>\n");

	ft_printf("my: %05u|\n", 0);
	printf("og: %05u|\n", 0);
	ft_printf("my: %05u|\n", -7);
	printf("og: %05u|\n", -7);
	ft_printf("my: %012u|\n", 120);
	printf("og: %012u|\n", 120);
	ft_printf("my: %05u|\n", 1560133635);
	printf("og: %05u|\n", 1560133635);
	ft_printf("my: %05u|\n", -2035065302);
	printf("og: %05u|\n", -2035065302);


	printf("\n<|######--RIGHT  ALIGN--######|>\n");
	// RIGHT ALIGN
	ft_printf("my: %+-5u|\n", 0);
	printf("og: %+-5u|\n", 0);
	ft_printf("my: %+-5u|\n", -7);
	printf("og: %+-5u|\n", -7);
	ft_printf("my: %+-5u|\n", 1560133635);
	printf("og: %+-5u|\n", 1560133635);
	ft_printf("my: %+-5u|\n", -2035065302);
	printf("og: %+-5u|\n", -2035065302);

	printf("\n<|############################|>\n");

	ft_printf("my: %-05u|\n", 0);
	printf("og: %-05u|\n", 0);
	ft_printf("my: %-05u|\n", -7);
	printf("og: %-05u|\n", -7);
	ft_printf("my: %-012u|\n", 120);
	printf("og: %-012u|\n", 120);
	ft_printf("my: %-012u|\n", -120);
	printf("og: %-012u|\n", -120);
	ft_printf("my: %-05u|\n", 1560133635);
	printf("og: %-05u|\n", 1560133635);
	ft_printf("my: %-05u|\n", -2035065302);
	printf("og: %-05u|\n", -2035065302);

	printf("\n<|########--PRECISION--#######|>\n");

	ft_printf("my: %-+.9u|\n", 7);
	printf("og: %-+.9u|\n", 7);
	ft_printf("my: %-+.9u|\n", -7);
	printf("og: %-+.9u|\n", -7);
	ft_printf("my: %-.15u|\n", 722);
	printf("og: %-.15u|\n", 722);;
	ft_printf("my: %+.5u|\n", 7);
	printf("og: %+.5u|\n", 7);
	ft_printf("my: %+.1u|\n", 7);
	printf("og: %+.1u|\n", 7);
	ft_printf("my: %.u|\n", 7);
	printf("og: %.u|\n", 7);
	ft_printf("my: %.-1u|\n", 7);
	printf("og: %.-1u|\n", 7);

	printf("\n<|############################|>\n");
}

void	hex_checker()
{
	printf("\n<|######--LEFT   ALIGN--######|>\n");

	ft_printf("my: %x|\n", 0);
	printf("og: %x|\n", 0);
	ft_printf("my: %x|\n", -7);
	printf("og: %x|\n", -7);
	ft_printf("my: %x|\n", 1560133635);
	printf("og: %x|\n", 1560133635);
	ft_printf("my: %x|\n", -2035065302);
	printf("og: %x|\n", -2035065302);

	// PLUS
	printf("\n<|############################|>\n");

	ft_printf("my: %+15x|\n", 0);
	printf("og: %+15x|\n", 0);
	ft_printf("my: %+14x|\n", 12);
	printf("og: %+14x|\n", 12);
	ft_printf("my: %+14x|\n", -7);
	printf("og: %+14x|\n", -7);
	ft_printf("my: %+14x|\n", 1560133635);
	printf("og: %+14x|\n", 1560133635);
	ft_printf("my: %+14x|\n", -2035065302);
	printf("og: %+14x|\n", -2035065302);

	printf("\n<|############################|>\n");

	ft_printf("my: %#13.5lx|\n", 0);
	printf("og: %#13.5lx|\n", 0);
	ft_printf("my: %#+13.10lx|\n", 0);
	printf("og: %#+13.10lx|\n", 0);
	ft_printf("my: %#+16.5lx|\n", 42);
	printf("og: %#+16.5lx|\n", 42);;
	ft_printf("my: %#+5x|\n", -7);
	printf("og: %#+5x|\n", -7);
	ft_printf("my: %+5x|\n", 1560133635);
	printf("og: %+5x|\n", 1560133635);
	ft_printf("my: %+5x|\n", -2035065302);
	printf("og: %+5x|\n", -2035065302);


	printf("\n<|############################|>\n");

	ft_printf("my: %5x|\n", 0);
	printf("og: %5x|\n", 0);
	ft_printf("my: %05x|\n", -7);
	printf("og: %05x|\n", -7);
	ft_printf("my: %012x|\n", 120);
	printf("og: %012x|\n", 120);
	ft_printf("my: %012x|\n", -120);
	printf("og: %012x|\n", -120);
	ft_printf("my: %#05x|\n", 1560133635);
	printf("og: %#05x|\n", 1560133635);
	ft_printf("my: %05x|\n", -2035065302);
	printf("og: %05x|\n", -2035065302);
	ft_printf("my: %10.07x|\n", 123456);
	printf("og: %10.07x|\n", 123456);
	ft_printf("my: %10.05x|\n", 123456);
	printf("og: %10.05x|\n", 123456);

	printf("\n<|######--RIGHT  ALIGN--######|>\n");
	// RIGHT ALIGN
	ft_printf("my: %#-+13.5lx|\n", 0);
	printf("og: %#-+13.5lx|\n", 0);
	ft_printf("my: %#-+16.5lx|\n", 42);
	printf("my: %#-+16.5lx|\n", 42);
	ft_printf("my: %05x|\n", -7);
	printf("og: %05x|\n", -7);
	ft_printf("my: %012x|\n", 120);
	printf("og: %012x|\n", 120);
	ft_printf("my: %012x|\n", -120);
	printf("og: %012x|\n", -120);
	ft_printf("my: %#05x|\n", 1560133635);
	printf("og: %#05x|\n", 1560133635);
	ft_printf("my: %05x|\n", -2035065302);
	printf("og: %05x|\n", -2035065302);
	ft_printf("my: %10.07x|\n", 123456);
	printf("og: %10.07x|\n", 123456);
	ft_printf("my: %10.05x|\n", 123456);
	printf("og: %10.05x|\n", 123456);

	printf("\n<|######--RIGHT  ALIGN--######|>\n");
	// RIGHT ALIGN
	ft_printf("my: %#-+13.5lx|\n", 0);
	printf("og: %#-+13.5lx|\n", 0);
	ft_printf("my: %#-+16.5lx|\n", 42);
	printf("og: %#-+16.5lx|\n", 42);;
	ft_printf("my: %#+-5x|\n", -7);
	printf("og: %#+-5x|\n", -7);
	ft_printf("my: %+-5x|\n", 1560133635);
	printf("og: %+-5x|\n", 1560133635);
	ft_printf("my: %+-5x|\n", -2035065302);
	printf("og: %+-5x|\n", -2035065302);


	ft_printf("my: %-05x|\n", 0);
	printf("og: %-05x|\n", 0);
	ft_printf("my: %-05x|\n", -7);
	printf("og: %-05x|\n", -7);
	ft_printf("my: %-012x|\n", 120);
	printf("og: %-012x|\n", 120);
	ft_printf("my: %-012x|\n", -120);
	printf("og: %-012x|\n", -120);
	ft_printf("my: %#-05x|\n", 1560133635);
	printf("og: %#-05x|\n", 1560133635);
	ft_printf("my: %-05x|\n", -2035065302);
	printf("og: %-05x|\n", -2035065302);

	printf("\n<|############################|>\n");
}

#include <limits.h>
int main()
{
	int		integer = 1223;
	float	real_num = 0.231;
	char	c = 'a';
	char	*c_ptr = &c;
	char	*str = "string!";
	int n = 221322;
//	decimal_checker();
//	unsigned_decimal_checker();
	hex_checker();
	long int    lnb = LONG_MAX;
	long int    lnb_neg = LONG_MIN;
	long int    lnb_0 = 0;

	ft_printf("\n%08x|\n", 12);
	printf("\n%08x|\n", 12);


//	ft_printf("Faux : |||%ld||| %ld |||-%ld/\n", lnb, lnb_neg, lnb_0);
//	printf("Vrai : |||%ld||| %ld |||-%ld/\n", lnb, lnb_neg, lnb_0);
//	ft_printf("Faux : |||%ld||| %ld |||-%ld/\n", lnb, lnb_neg - 1, lnb_0);
//	printf("Vrai : |||%ld||| %ld |||-%ld/\n", lnb, lnb_neg - 1, lnb_0);
	/*printf("itoa_bas	decimal_checker();e: %s\n", itoa_base(15, 16));*/
	return (0);
}
