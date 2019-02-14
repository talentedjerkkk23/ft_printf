
#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	argp;
	t_fmt *f;
	int len;

	f = (t_fmt*)malloc(sizeof(t_fmt));
	reset_format(f);
	f->total_len = 0;
	va_start(argp, fmt);
	ft_parse_args(fmt, f, argp);
	va_end(argp);
	len = f->total_len;
	free(f);
	return (len);
}
