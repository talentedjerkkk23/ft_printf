#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
# define H 1
# define HH 2
# define L 3
# define LL 4
# define HASH 1
# define PLUS 2
# define MINUS 3
# define ZERO 4
# define SPACE 5

typedef union	s_double {
	double f;
	unsigned long u;
}				t_double;

typedef union	s_float {
	float f;
	unsigned u;
	unsigned char exp;
	unsigned long mantissa;
	char *sign;
}				t_float;

typedef struct	s_fmt
{
	int		fd;
	int		total_len;
	int		i;
	int		curr_len;
	short	hash;
	short	plus;
	short	minus;
	short	zero;
	short 	space;
	short	adjust;
	int		field_width;
	int 	len_modif;
	int		precision;
	short 	have_prec;
	short 	mode;
}				t_fmt;

void			print_floating_point(t_fmt *f, va_list ap);
void			print_char(t_fmt *f, va_list ap);
void			print_octal(t_fmt *f, va_list ap);
void			print_hex(short mode, t_fmt *f, va_list ap);
void			print_unsigned_decimal(t_fmt *f, va_list ap);
void			print_decimal(t_fmt *f, va_list ap);
long			calc_len(long n, long count);
int     		ft_parse_args(const char *fmt, t_fmt *f, va_list ap);
void			reset_format(t_fmt *f);
void			print(const char *fmt, t_fmt *f, va_list ap);
#endif
