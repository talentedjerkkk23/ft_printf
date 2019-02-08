#include "ft_printf.h"




void	print(const char *fmt, t_fmt *f, va_list ap)
{
	if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(f, ap);
	else if (fmt[f->i] == 'u')
		print_unsigned_decimal(f, ap);
	else if (fmt[f->i] == 'x' || fmt[f->i] == 'X')
		print_hex((fmt[f->i] == 'x' ? (short)1 : (short)2), f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(f, ap);
}
