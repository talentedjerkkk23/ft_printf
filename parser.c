#include "ft_printf.h"

void	set_len_modif(const char *fmt, t_fmt *f)
{
	while (ft_strchr("hlL", fmt[f->i]))
	{
		if (fmt[f->i] == 'h')
		{
			f->len_modif = H;
			if (fmt[f->i + 1] == 'h')
			{
				f->len_modif = HH;
				(f->i)++;
			}
		}
		else if (fmt[f->i] == 'l')
		{
			f->len_modif = L;
			if (fmt[f->i + 1] == 'l')
			{
				f->len_modif = LL;
				(f->i)++;
			}
		}
		else if (fmt[f->i] == 'L')
			f->len_modif = LL;
		(f->i)++;
	}

}

void 	set_precision(const char *fmt, t_fmt *f)
{
	if (fmt[f->i] == '.')
		(f->i)++;
	f->precision = ft_atoi(&fmt[f->i]);
	while (ft_isdigit(fmt[f->i]))
		(f->i)++;
}

void 	set_width(const char *fmt, t_fmt *f)
{
	if (ft_isdigit(fmt[f->i]))
	{
		f->field_width = ft_atoi(&fmt[f->i]);
	}
	while (ft_isdigit(fmt[f->i]))
		(f->i)++;
}

void 	set_flags(const char *fmt, t_fmt *f)
{
	while (ft_strchr(" #+-0", fmt[f->i]))
	{
			if (fmt[f->i] == '#')
				f->hash = 1;
			else if (fmt[f->i] == ' ')
				f->space = 1;
			else if (fmt[f->i] == '+')
				f->plus = 1;
			else if (fmt[f->i] == '-')
				f->minus = 1;
			else if (fmt[f->i] == '0')
				f->zero = 1;
			(f->i)++;
	}
}

void	ft_set_output_format(const char *fmt, t_fmt *f)
{
	set_flags(fmt, f);
	set_width(fmt, f);
	set_precision(fmt, f);
	set_len_modif(fmt, f);
}
/*
 *
%[flag][min width][precision][length modifier][conversion specifier]

*/
int		ft_parse_args(const char *fmt, t_fmt *f, va_list ap)
{
	f->i = 0;
	while (fmt[f->i] != '\0')
	{
		if (fmt[f->i] == '%')
		{
			(f->i)++;
			if (ft_strchr(" -+#.0123456789hlL", fmt[f->i]))
				ft_set_output_format(fmt, f);
			if (ft_strchr("csSpdioOuUxXf%", fmt[f->i]))
			{
				print(fmt, f, ap);
			}
		}
		else
		{
			write(1, &fmt[f->i], 1);
		}
		(f->i)++;
	}
    return (f->total_len);
}
