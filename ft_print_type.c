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
<<<<<<< HEAD
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
=======
	if (f->len_modif == H)
		return ((short)va_arg(ap, long));
	else if (f->len_modif == HH)
		return ((char)va_arg(ap, long));
	else if (f->len_modif == L)
		return (va_arg(ap, long));
	else if (f->len_modif == H)
		return ((long long)va_arg(ap, long));
	return (va_arg(ap, long));
>>>>>>> cbf43dc43f4d1a30b6c95dbd16159741680ef000
}
void	print_decimal(const char *fmt, t_fmt *f, va_list ap)
{
	long n;
	char *num;

	n = calc_len_mod(f, ap);
	num = ft_ltoa(n);
<<<<<<< HEAD
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
=======
	if (f->plus)
	{

	}
	f->total_len = l_strlen(ft_ltoa(n));
	write(1, num, l_strlen(num));
>>>>>>> cbf43dc43f4d1a30b6c95dbd16159741680ef000
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