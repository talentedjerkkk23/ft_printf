#include "ft_printf.h"

int 	l_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
long 	calc_len_mod(t_fmt *f, va_list ap)
{
	if (f->len_modif == H)
		return ((short)va_arg(ap, long));
	else if (f->len_modif == HH)
		return ((char)va_arg(ap, long));
	else if (f->len_modif == L)
		return (va_arg(ap, long));
	else if (f->len_modif == H)
		return ((long long)va_arg(ap, long));
	return (va_arg(ap, long));
}
void	print_decimal(const char *fmt, t_fmt *f, va_list ap)
{
	long n;
	char *num;

	n = calc_len_mod(f, ap);
	num = ft_ltoa(n);
	if (f->plus)
	{

	}
	f->total_len = l_strlen(ft_ltoa(n));
	write(1, num, l_strlen(num));
}

void	print_float(const char *fmt, t_fmt *f, va_list ap)
{

}

void	print(const char *fmt, t_fmt *f, va_list ap)
{
	if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(fmt, f, ap);
	else if (fmt[f->i] == 'f' || fmt[f->i] == 'F')
		print_float(fmt, f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(fmt, f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(fmt, f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(fmt, f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(fmt, f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(fmt, f, ap);
	else if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(fmt, f, ap);

}