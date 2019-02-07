#include "ft_printf.h"


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

char *itoa_base(int value, int base)
{
	char rep[] = "0123456789abcdef";
	char *buf = (char*)malloc(sizeof(char) * 50);
	char    *ptr;
	int     num;

	ptr = &buf[49];
	*ptr = '\0';
	num = value;
	if (value < 0 && base == 10)
		value *= -1;
	if (value == 0)
		*--ptr = rep[value % base];
	while (value != 0)
	{
		*--ptr = rep[value % base];
		value /= base;
	}
	if (num < 0 && base == 10)
		*--ptr = '-';
	return (ptr);
}