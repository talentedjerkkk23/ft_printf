#include "ft_printf.h"

long	calc_len(long n, long count)
{
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n > 9)
	{
		calc_len(n / 10, count);
		count++;
	}
	return (count);
}


ft_write_with_len(const char *fmt, t_fmt *f, va_list ap)
{

}
