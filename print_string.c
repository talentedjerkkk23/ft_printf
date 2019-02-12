#include "ft_printf.h"

static int 	l_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	write_left_align(t_fmt *f, char *num, int num_len)
{
	int		i;

	i = 0;
	while (f->have_prec && f->field_width-- > f->precision)
		f->total_len += write(1, " ", 1);
	while (f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
	while (f->have_prec && num[i] && f->precision--)
		f->total_len += write(1, &num[i++], 1);
	while (!f->have_prec && num[i])
		f->total_len += write(1, &num[i++], 1);
}

static void	write_right_align(t_fmt *f, char *num, int num_len)
{
	int		i;
	int		pr;

	pr = f->precision;
	i = 0;
	while (f->have_prec && num[i] && f->precision--)
		f->total_len += write(1, &num[i++], 1);
	while (!f->have_prec && num[i])
		f->total_len += write(1, &num[i++], 1);
	while (f->have_prec && f->field_width-- > pr)
		f->total_len += write(1, " ", 1);
	while (f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
}

void	print_str(t_fmt *f, va_list ap)
{
	char	*num;
	char	*s;
	int		num_len;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	num = ft_strdup(s);
	num_len = l_strlen(num);
	if (f->minus)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	if (f->minus)
		write_right_align(f, num, num_len);
	else
		write_left_align(f, num, num_len);
	free(num);
}

