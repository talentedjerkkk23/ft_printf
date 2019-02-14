

#include <math.h>
#include "ft_printf.h"

static int 	l_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
static long double	calc_len_mod(t_fmt *f, va_list ap)
{
	long double n;

	if (f->len_modif == L)
		n = (double)(va_arg(ap, double));
	else if (f->len_modif == LL)
		n = (va_arg(ap, long double));
	else
		n = (double)(va_arg(ap, double));
	return(n);
}

static void	write_left_align(t_fmt *f, char *num, long double n, int num_len)
{
	int		i;

	/*i = (n < 0) ? 1 : 0;*/
	n--;
	num_len--;
	print_rounded(&num, f->precision);
	i = 0;
	while (num[i] && num[i] != '.')
		f->total_len += write(1, &num[i++], 1);
	f->total_len += write(1, &num[i++], 1);
	while (num[i] && f->precision)
	{
		f->total_len += write(1, &num[i++], 1);
		f->precision--;
	}
}

static void	write_right_align(t_fmt *f, char *num, long double  n, int num_len)
{
	int i;
	/*i = (n < 0) ? 1 : 0;*/
	i = 0;
	n--;
	num_len--;
	print_rounded(&num, f->precision);
	while (num[i] && num[i] != '.')
		f->total_len += write(1, &num[i++], 1);
	while (num[i] && f->precision--)
		f->total_len += write(1, &num[i++], 1);
}

void	print_floating_point(t_fmt *f, va_list ap)
{
	long double n;
	char *num;
	int num_len;

	n = calc_len_mod(f, ap);
	/*printf("n: %Lf\n", n);*/
	if (n < 0)
		f->fl_sign = 1;
	if (!f->have_prec)
		f->precision = 6;
	num = double_to_str(n, f->precision + 19);
	/*printf("\nnum: %s\n", num);*/
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
