#include "ft_printf.h"

static int 	l_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
static unsigned long	calc_len_mod(t_fmt *f, va_list ap)
{
	unsigned long n;
	if (f->len_modif == H)
		n = ((unsigned short)va_arg(ap, unsigned long));
	else if (f->len_modif == HH)
		n = ((unsigned char)va_arg(ap, unsigned long));
	else if (f->len_modif == L)
		n = (va_arg(ap, unsigned long));
	else if (f->len_modif == LL)
		n =  ((unsigned long long)va_arg(ap, unsigned long));
	else
		n = (unsigned int)(va_arg(ap, unsigned long));
	return(n);
}

static void	write_left_align(t_fmt *f, char *num, unsigned long n, int num_len)
{
	int		i;
	int		is_pl;

	is_pl = 0;
	i = (n < 0) ? 1 : 0;
	if ((f->space || f->plus) && f->precision == -1)
		f->total_len += write(1, " ", 1);
	while (!f->zero && f->precision == -1 && f->field_width-- > (num_len + ((n < 0) ? 0 : 1)))
		f->total_len += write(1, " ", 1);
	while (f->zero && f->field_width-- > (num_len + ((n < 0) ? 0 : 1)))
		f->total_len += write(1, "0", 1);
	while (f->precision-- > num_len)
		f->total_len += write(1, "0", 1);
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
}

static void	write_right_align(t_fmt *f, char *num, unsigned long n, int num_len)
{
	int i;
	i = (n < 0) ? 1 : 0;
	if (f->precision > num_len)
	{
		while (f->precision-- > (num_len))
			f->total_len += write(1, "0", 1);
	}
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
	while (f->precision >= 0 && f->field_width >= num_len && f->field_width-- > f->precision)
		f->total_len += write(1, " ", 1);
	while (f->plus && f->field_width-- > (num_len) && f->precision == -1)
		f->total_len += write(1, " ", 1);
	while (!f->plus && f->field_width-- > (num_len ) && f->precision == -1)
		f->total_len += write(1, " ", 1);
}

void	print_unsigned_decimal(const char *fmt, t_fmt *f, va_list ap)
{
	unsigned long n;
	char *num;
	int num_len;

	n = calc_len_mod(f, ap);
	num = ft_ltoa(n);
	num_len = l_strlen(num);
	if (f->minus)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	if (f->minus)
		write_right_align(f, num, n, num_len);
	else
		write_left_align(f, num, n, num_len);
	free(num);
}
