/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palan <palan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:54:37 by palan             #+#    #+#             */
/*   Updated: 2019/02/15 19:02:02 by palan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_format(t_fmt *f)
{
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
	f->fl_sign = 0;
	f->is_pl = 0;
}
