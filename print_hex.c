/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talentedjerk <talentedjerk@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:08:10 by palan             #+#    #+#             */
/*   Updated: 2019/02/16 00:08:18 by talentedjer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	calc_len_mod(t_fmt *f, va_list ap)
{
	uintmax_t n;

	if (f->len_modif == H)
		n = ((unsigned short)va_arg(ap, uintmax_t));
	else if (f->len_modif == HH)
		n = ((unsigned char)va_arg(ap, uintmax_t));
	else if (f->len_modif == L)
		n = (va_arg(ap, uintmax_t));
	else if (f->len_modif == LL)
		n = ((unsigned long long)va_arg(ap, uintmax_t));
	else
		n = (unsigned int)(va_arg(ap, uintmax_t));
	return (n);
}

static void				write_left_align(t_fmt *f,
char *num, uintmax_t n, int num_len)
{
	int		i;

	i = 0;
	while (!f->zero && f->precision <= num_len && f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
	/*while (!f->zero && f->have_prec && f->field_width-- > (f->precision))*/
		/*f->total_len += write(1, " ", 1);*/
	if (f->hash && n != 0)
	{
		f->total_len += write(1, (f->mode == 1 ? "0x" : "0X"), 2);
	}
	while (f->precision-- > num_len)
		f->total_len += write(1, "0", 1);
	while (f->zero && f->field_width-- > (num_len))
		f->total_len += write(1, "0", 1);
	/*printf("prec: %d\n", f->precision);*/
	/*printf("have_prec: %d\n", f->have_prec);*/
	if (((f->have_prec && f->precision > 0) || n != 0) || !f->have_prec)
	{
		while (num[i])
			f->total_len += write(1, &num[i++], 1);
	}
	else
		f->total_len += write(1, " ", 1);

}

static void				write_right_align(t_fmt *f,
char *num, uintmax_t n, int num_len)
{
	int		i;

	i = 0;
	if (f->hash && n != 0)
		f->total_len += write(1, (f->mode == 1 ? "0x" : "0X"), 2);
	if (f->precision > f->field_width)
	{
		while (f->precision-- > num_len)
		{
			f->field_width--;
			f->total_len += write(1, "0", 1);
		}
	}
	while (f->precision-- > num_len && f->field_width)
	{
		f->field_width--;
		f->total_len += write(1, "0", 1);
	}
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
	while (!f->zero && f->field_width-- > num_len)
		f->total_len += write(1, "  ", 1);
}

void					print_hex(short mode, t_fmt *f, va_list ap)
{
	uintmax_t	n;
	char			*num;
	int				num_len;

	f->mode = mode;
	n = calc_len_mod(f, ap);
	num = ft_ltoa_base(n, 16, mode);
	num_len = l_strlen(num);
	if (n == 0 && f->have_prec && f->precision == 0 && f->field_width == 0)
		return ;
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
