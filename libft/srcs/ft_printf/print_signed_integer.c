/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed_integer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:08:59 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/10 16:13:20 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			signed_cast(intmax_t *value, t_ft_pf *spec, va_list ap)
{
	if (spec->type == 'D')
	{
		*value = (long long)va_arg(ap, long long);
		return ;
	}
	if (spec->size == nosize)
		*value = (int)va_arg(ap, int);
	if (spec->size == l)
		*value = (long)va_arg(ap, long);
	if (spec->size == ll)
		*value = (long long)va_arg(ap, long long);
	if (spec->size == L)
		*value = (int64_t)va_arg(ap, int64_t);
	if (spec->size == h)
		*value = (short)va_arg(ap, int);
	if (spec->size == hh)
		*value = (char)va_arg(ap, int);
	if (spec->size == z)
		*value = (ssize_t)va_arg(ap, ssize_t);
	if (spec->size == j)
		*value = (intmax_t)va_arg(ap, intmax_t);
	if (spec->size == t)
		*value = (ptrdiff_t)va_arg(ap, ptrdiff_t);
}

void			correct_size_signed(t_ft_pf *spec, t_pf_number *num)
{
	if (spec->flags & PF_HASH)
		spec->flags = (spec->flags & 0xF7);
	if (spec->flags & PF_SPACE && (spec->flags & PF_PLUS || num->value->i < 0))
		spec->flags = (spec->flags & 0xFB);
	if ((spec->flags & PF_MINUS || spec->prec >= 0) && spec->flags & PF_ZERO)
		spec->flags = (spec->flags & 0xEF);
	if (spec->flags & PF_PLUS && num->value->i < 0)
		spec->flags = (spec->flags & 0xFE);
	if ((int)spec->field_size == spec->prec || spec->field_size == num->nb_len)
	{
		if (spec->flags & PF_SPACE || spec->flags & PF_PLUS || \
		num->value->i < 0)
			spec->field_size++;
	}
}

int				handle_signed_integer(t_ft_pf *spec, va_list ap)
{
	t_val		value;
	t_pf_number	*number;
	int			ret;

	signed_cast(&(value.i), spec, ap);
	number = new_number(&value, ft_unblen_base(PF_ABS(value.i), 10), 10);
	if (zero_with_zero_prec(spec, number) && spec->f_width == 0)
		spec->field_size = 0;
	else
	{
		spec->field_size = (size_t)PF_MAX(spec->prec, (int)number->nb_len);
		spec->field_size = PF_MAX(spec->f_width, spec->field_size);
	}
	correct_size_signed(spec, number);
	if (value.i < 0)
		number->sign = 1;
	if (spec->flags & PF_PLUS)
		number->sign = 2;
	ret = print_signed_integer(spec, number);
	ft_strdel(&(number->nb_str));
	ft_memdel((void**)&number);
	return (ret);
}

int				print_signed_integer(t_ft_pf *spec, t_pf_number *number)
{
	number->nb_str = fill_precision(spec, number);
	if (spec->flags & PF_MINUS)
		return (left_align(spec, number));
	else
		return (right_align(spec, number));
}
