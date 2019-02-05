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
	long n;
	if (f->len_modif == H)
		n = ((short)va_arg(ap, long));
	else if (f->len_modif == HH)
		n = ((char)va_arg(ap, long));
	else if (f->len_modif == L)
		n =  (va_arg(ap, long));
	else if (f->len_modif == LL)
		n =  ((long long)va_arg(ap, long));
	else
		n = (int)(va_arg(ap, long));
	return(n);
}
void	print_decimal(const char *fmt, t_fmt *f, va_list ap)
{
	long n;
	char *num;

	n = calc_len_mod(f, ap);
	num = ft_ltoa(n);
	while (f->field_width > (n < 0 ? l_strlen(num) : l_strlen(num) + 1) && f->field_width-- > f->precision)
		write(1, " ", 1);
	if (f->plus)
		write(1, ((num[0] == '-') ? "-" : "+"), 1);
	if (f->precision > l_strlen(num))
		while ((num[0] == -1 ? f->curr_len : f->curr_len - 1) + l_strlen(num) < f->precision + (n < 0) ? 1 : 0)
		{
				write(1, "0", 1);
				f->curr_len++;
		}
	write(1, ((num[0] == '-') ? (++num) : num), l_strlen(num));
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
