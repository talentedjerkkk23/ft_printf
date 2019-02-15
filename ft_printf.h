/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 18:52:40 by palan             #+#    #+#             */
/*   Updated: 2019/02/15 19:01:37 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

struct                    s_ldbits
{
    unsigned long        man : 64;
    unsigned long        exp : 15;
    unsigned long        sign : 1;
};

typedef union            u_ldbl
{
    long double            f;
    struct s_ldbits        b;
}                        t_ldbl;

struct                    s_dbits
{
    unsigned long        man : 52;
    unsigned long        exp : 11;
    unsigned long        sign : 1;
};

typedef union            u_dbl
{
    double            f;
    struct s_dbits        b;
}                        t_dbl;

struct                    s_floatbits
{
    unsigned long        man : 23;
    unsigned long        exp : 8;
    unsigned long        sign : 1;
};

typedef union            u_fbl
{
    float            f;
    struct s_floatbits        b;
}                        t_fbl;



typedef union	s_ldouble {
	long double f;
	unsigned long long u;
}				t_ldouble;

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
	int			fd;
	int			total_len;
	int			i;
	short		hash;
	short		plus;
	short		minus;
	short		zero;
	short		space;
	short		adjust;
	int			field_width;
	int			len_modif;
	int			precision;
	short		pmf;
	short		have_prec;
	short		mode;
	short		fl_sign;
	int			is_pl;
}				t_fmt;

int				l_strlen(char *str);
void			set_width(const char *fmt, t_fmt *f);
int				ft_printf(const char *fmt, ...);
void			print_rounded(char **str, int prec);
char			*long_double_to_str(long double num, int k_prec);
char			*double_to_str(double num, int k_prec);
void			print_str(t_fmt *f, va_list ap);
void			print_ptr(t_fmt *f, va_list ap);
void			print_floating_point(t_fmt *f, va_list ap);
void			print_char(t_fmt *f, va_list ap);
void			print_octal(t_fmt *f, va_list ap);
void			print_hex(short mode, t_fmt *f, va_list ap);
void			print_unsigned_decimal(t_fmt *f, va_list ap);
void			print_decimal(t_fmt *f, va_list ap);
long			calc_len(long n, long count);
int				ft_parse_args(const char *fmt, t_fmt *f, va_list ap);
void			reset_format(t_fmt *f);
void			print(const char *fmt, t_fmt *f, va_list ap);

#endif
