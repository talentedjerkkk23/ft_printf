
#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	argp;
	t_fmt *f;

	f = (t_fmt*)malloc(sizeof(t_fmt));
	reset_format(f);
	f->total_len = 0;
	va_start(argp, fmt);
	ft_parse_args(fmt, f, argp);
	va_end(argp);
	return (1);
}

char hex_digit(int n)
{
	if (n >= 0 && n < 10)
		return ('0' + n);
	else
		return ('a' + n - 10);
}

void print_address_hex(void* p0) {
	int i;
	unsigned long p = (unsigned long)p0;
	ft_putchar('0');
	ft_putchar('x');
	for(i = (sizeof(p) << 3) - 4; i >= 0; i -= 4) {
		ft_putchar(hex_digit((p >> i) & 0xf));
	}
}

void	decimal_checker()
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
	ft_printf("my: %+14d|\n", -7);
	printf("og: %+14d|\n", -7);
	ft_printf("my: %+14d|\n", 1560133635);
	printf("og: %+14d|\n", 1560133635);
	ft_printf("my: %+14d|\n", -2035065302);
	printf("og: %+14d|\n", -2035065302);

	// SPACE
	long double a = 2.2323;
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

	printf("\n<|############################|>\n");

	printf("<|######--RIGHT  ALIGN--######|>\n");
	// RIGHT ALIGN
	ft_printf("my: %+-5d|\n", 0);
	printf("og: %+-5d|\n", 0);
	ft_printf("my: %+-5d|\n", -7);
	printf("og: %+-5d|\n", -7);
	ft_printf("my: %+-5|d\n", 1560133635);
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
	ft_printf("my: %-05d|\n", 1560133635);
	printf("og: %-05d|\n", 1560133635);
	ft_printf("my: %-05d|\n", -2035065302);
	printf("og: %-05d|\n", -2035065302);

	printf("\n<|########--PRECISION--#######|>\n");
	ft_printf("my: % ++.9+0.9d|\n", 7);
	printf("og: % -+.9d|\n", 7);
	printf("\n<|############################|>\n");
}


int main()
{
	int		integer = 1223;
	float	real_num = 0.231;
	char	c = 'a';
	char	*c_ptr = &c;
	char	*str = "string!";
	int n = 221322;
	decimal_checker();
	return (0);
}
