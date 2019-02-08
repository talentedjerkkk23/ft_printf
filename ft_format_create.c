#include "ft_printf.h"

void	reset_format(t_fmt *f)
{
	f->curr_len = 0;
	f->hash = 0;
	f->plus = 0;
	f->minus = 0;
	f->zero = 0;
	f->space = 0;
	f->precision = 0;
	f->len_modif = 0;
	f->have_prec = 0;
	f->field_width = 0;
	f->mode = 0;
}
