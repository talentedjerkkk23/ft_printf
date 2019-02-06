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

void	write_left_align(t_fmt *f, char *num, long n, int num_len)
{
	if (f->space && !f->plus)
		write(1, " ", 1);
	if (!f->plus && f->zero && n < 0)
		write(1, "-", 1);
	while (f->precision >= 0 && f->field_width-- > f->precision)
		write(1, " ", 1);
	while (!f->zero && f->field_width-- > num_len && f->precision == -1)
		f->total_len += write(1, " ", 1);
	while (f->zero && f->field_width-- > l_strlen(num))
		write(1, "0", 1);
	while (f->zero && f->precision-- > l_strlen(num))
		write(1, "0", 1);
	if (f->plus)
		write(1, ((num[0] == '-') ? "-" : "+"), 1);
	else if (!f->zero && n < 0)
		write(1, "-", 1);

	write(1, ((num[0] == '-') ? (++num) : num), l_strlen(num));
}

void	write_right_align(t_fmt *f, char *num, long n, int num_len)
{
	if (f->plus)
		write(1, ((num[0] == '-') ? "-" : "+"), 1);
	else if (n < 0)
		write(1, "-", 1);
	if (f->precision > l_strlen(num))
		while (num_len < f->precision-- + (n < 0) ? 1 : 0)
		{
			write(1, "0", 1);
			f->curr_len++;
		}
	write(1, ((num[0] == '-') ? (++num) : num), l_strlen(num));
	while (f->precision >= 0 && f->field_width > num_len && f->field_width-- > f->precision)
		write(1, " ", 1);
	while (f->field_width-- > num_len && f->precision == -1)
		f->total_len += write(1, " ", 1);

}

void	print_decimal(const char *fmt, t_fmt *f, va_list ap)
{
	long n;
	char *num;
	int num_len;

	n = calc_len_mod(f, ap);
	num = ft_ltoa(n);
	num_len = (n >= 0) ? l_strlen(num) + 1 : l_strlen(num);
	if (f->minus)
		write_right_align(f, num, n, num_len);
	else
		write_left_align(f, num, n, num_len);
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
