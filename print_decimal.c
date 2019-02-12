#include "ft_printf.h"

static int 	l_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
static long 	calc_len_mod(t_fmt *f, va_list ap)
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

static void	write_left_align(t_fmt *f, char *num, long n, int num_len)
{
	int		i;
	int		is_pl;

	is_pl = 0;
	i = (n < 0) ? 1 : 0;
	while (f->have_prec && f->field_width-- > (f->precision))
		f->total_len += write(1, " ", 1);
	if (f->space && !f->plus && n > 0)
		f->total_len += write(1, " ", 1);
	if (!f->plus && f->zero && n < 0)
		f->total_len += write(1, "-", 1);
	if (f->plus && (f->precision >= num_len)) 
	{
		f->total_len += write(1, ((num[0] == '-') ? "-" : "+"), 1);
		is_pl = 1;
	}
	while (!f->zero && !f->have_prec && f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
	while (f->zero && f->field_width-- > num_len)
		f->total_len += write(1, "0", 1);
	while (f->precision-- > (num_len))
		f->total_len += write(1, "0", 1); 
	if (f->plus && f->have_prec == 0 && is_pl == 0)
		f->total_len += write(1, ((num[0] == '-') ? "-" : "+"), 1);
	else if (!f->zero && n < 0 && is_pl == 0)
		f->total_len += write(1, "-", 1);
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
}

static void	write_right_align(t_fmt *f, char *num, long n, int num_len)
{
	int i;

	i = (n < 0) ? 1 : 0;
	if (f->plus)
		f->total_len += write(1, ((num[0] == '-') ? "-" : "+"), 1);
	else if (n < 0)
		f->total_len += write(1, "-", 1);
	if (f->precision > num_len)
	{
		while (f->precision-- > (num_len))
		{
			f->total_len += write(1, "0", 1);
			f->field_width--;
		}
	}
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
	while (!f->pmf && f->field_width-- > num_len)
		f->total_len += write(1, " ", 1); // all " "
	while (f->plus && f->field_width-- > (num_len + ((n < 0) ? 0 : 1)) && f->precision == -1)
		f->total_len += write(1, "#", 1);
	while (!f->plus && f->field_width-- > (num_len ) && f->precision == -1)
		f->total_len += write(1, "@", 1);
}

void	print_decimal(t_fmt *f, va_list ap)
{
	long	n;
	char	*num;
	int		num_len;

	n = calc_len_mod(f, ap);
	num = ft_ltoa(n);
	num_len = l_strlen(num);
	f->pmf = (f->precision > f->field_width) ? 1 : 0;
	if (f->minus)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	if (f->plus || n < 0)
		{
			f->field_width--;
			if (n < 0)
				num_len--;
		}
	if (f->minus)
		write_right_align(f, num, n, num_len);
	else
		write_left_align(f, num, n, num_len);
	free(num);
}
