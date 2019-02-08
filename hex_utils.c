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


