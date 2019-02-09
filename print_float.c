

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
		n =  (va_arg(ap, long double));
	else
		n = (float)(va_arg(ap, double));
	return(n);
}

int n_tu(int number, int count)
{
	int result = 1;
	while(count-- > 0)
		result *= number;

	return result;
}

/*** Convert float to string ***/
static void	write_left_align(t_fmt *f, char *num, unsigned long n, int num_len)
{
	int		i;

	i = (n < 0) ? 1 : 0;
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
}

static void	write_right_align(t_fmt *f, char *num, unsigned long n, int num_len)
{
	int i;
	i = (n < 0) ? 1 : 0;
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
}

void	print_floating_point(t_fmt *f, va_list ap)
{
	long double n;
	char *num;
	int num_len;
	int size;
	n = calc_len_mod(f, ap);

	num_len = l_strlen(num);
	if (!f->have_prec)
		f->precision = 6;
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