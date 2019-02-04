
#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	argp;
	t_fmt *f;

	f = (t_fmt*)malloc(sizeof(t_fmt));
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


int main()
{
	int		integer = 1223;
	float	real_num = 0.231;
	char	c = 'a';
	char	*c_ptr = &c;
	char	*str = "string!";

	//print_address_hex((void*) str);
	ft_printf("%0.321d\n", 12);
	printf("%d\n", 12);
//	printf("%lu\n", sizeof(t_fmt));
//	printf("%p\a\n", (void*)str);
//	printf("int: %.5d \nfloat: %f\nchar: %c\nchar*: %s\n", integer, real_num, c, str);
	/*printf("%0.121f", 12.234657);*/
	return (0);
}
