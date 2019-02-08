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

	i = 0;
	while (!f->zero && f->precision <= num_len && f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
	while (!f->zero && f->have_prec && f->field_width-- > (f->precision))
		f->total_len += write(1, " ", 1);
	if (f->hash && n != 0)
	{
		f->total_len += write(1, (f->mode == 1 ? "0x" : "0X"), 2);
//		if (f->field_width != 0)
//			f->field_width -= 2;
	}
	while (f->precision-- > num_len)
		f->total_len += write(1, "0", 1);
	while (f->zero && f->field_width-- > (num_len))
		f->total_len += write(1, "0", 1);
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
}

static void	write_right_align(t_fmt *f, char *num, unsigned long n, int num_len)
{
	int		i;

	i = 0;
	if (f->hash && n != 0)
	{
		f->total_len += write(1, (f->mode == 1 ? "0x" : "0X"), 2);
		if (f->field_width != 0)
			f->field_width -= 2;
	}
	while (f->precision-- > num_len)
		f->total_len += write(1, "0", 1);
	while (f->zero && f->field_width-- > (num_len))
		f->total_len += write(1, "0", 1);
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
	while (!f->zero && f->precision <= num_len && f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
	while (!f->zero && f->have_prec && f->field_width-- > (f->precision))
		f->total_len += write(1, " ", 1);
}

//static void	write_right_align(t_fmt *f, char *num, unsigned long n, int num_len)
//{
//	int i;
//	int pres;
//
//	pres = f->precision;
//	i = (n < 0) ? 1 : 0;
//	if (f->precision > num_len)
//	{
//		while (f->precision-- > (num_len))
//		{
//			f->total_len += write(1, "0", 1);
//		}
//	}
//	while (num[i])
//		f->total_len += write(1, &num[i++], 1);
//	while (f->field_width-- > (pres - num_len) && f->precision != -1)
//		f->total_len += write(1, "1", 1);
//	while (!f->plus && f->field_width-- > (num_len ) && f->precision == -1)
//		f->total_len += write(1, "2", 1);
//	while (f->plus && f->field_width-- > (num_len ) && f->precision == -1)
//		f->total_len += write(1, "3", 1);
//}

void	print_hex(short mode, t_fmt *f, va_list ap)
{
	unsigned long n;
	char *num;
	int num_len;

	f->mode = mode;
	n = calc_len_mod(f, ap);
	num = ft_itoa_base(n, 16, mode);
	num_len = l_strlen(num);
	if (f->minus)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	if (f->hash && n != 0)
	{
		if (f->field_width != 0)
			f->field_width -= 2;
	}
	if (f->minus)
		write_right_align(f, num, n, num_len);
	else
		write_left_align(f, num, n, num_len);
	free(num);
}
