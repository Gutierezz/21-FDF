/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_integer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:34:58 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/10 18:37:49 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				unsigned_cast(uintmax_t *u_value, t_ft_pf *spec, va_list ap)
{
	if (spec->type == 'p' || spec->type == 'U' || spec->type == 'O')
	{
		*u_value = (spec->type == 'p') ? \
		(unsigned long long)va_arg(ap, void*) : va_arg(ap, unsigned long long);
		spec->size = nosize;
		spec->flags |= (spec->type == 'p') ? PF_HASH : 0;
		return ;
	}
	if (spec->size == nosize)
		*u_value = (unsigned int)va_arg(ap, unsigned int);
	if (spec->size == l)
		*u_value = (unsigned long)va_arg(ap, unsigned long long);
	if (spec->size == ll)
		*u_value = (unsigned long long)va_arg(ap, unsigned long long);
	if (spec->size == L)
		*u_value = (uint64_t)va_arg(ap, uint64_t);
	if (spec->size == h)
		*u_value = (unsigned short)va_arg(ap, unsigned int);
	if (spec->size == hh)
		*u_value = (unsigned char)va_arg(ap, unsigned int);
	if (spec->size == z || spec->size == t)
		*u_value = (size_t)va_arg(ap, size_t);
	if (spec->size == j)
		*u_value = (uintmax_t)va_arg(ap, uintmax_t);
}

void				correct_size_unsigned(t_ft_pf *spec, t_pf_number *number)
{
	if (spec->flags & PF_HASH && spec->type != 'p')
	{
		if (number->base == 10)
			spec->flags = (spec->flags & 0xF7);
		if (number->value->ui == 0)
		{
			if (spec->prec == 0)
				spec->flags = (number->base == 16) ? spec->flags & 0xF7 : \
					spec->flags;
			else
				spec->flags = spec->flags & 0xF7;
		}
		if (number->base == 8 && spec->prec > (int)number->nb_len)
			spec->flags = (spec->flags & 0xF7);
	}
	if (spec->flags & PF_SPACE)
		spec->flags = (spec->flags & 0xFB);
	if (spec->flags & PF_ZERO)
	{
		if (spec->flags & PF_MINUS || (spec->prec >= 0))
			spec->flags = (spec->flags & 0xEF);
	}
	if (spec->flags & PF_PLUS)
		spec->flags = (spec->flags & 0xFE);
}

int					handle_unsigned_integer(t_ft_pf *spec, va_list ap)
{
	t_val			value;
	unsigned int	base;
	t_pf_number		*number;
	int				ret;

	base = get_int_base(spec->type);
	unsigned_cast(&(value.ui), spec, ap);
	number = new_number(&value, ft_unblen_base(value.ui, base), base);
	if (zero_with_zero_prec(spec, number) && spec->f_width == 0)
		spec->field_size = 0;
	else
	{
		spec->field_size = (size_t)PF_MAX(spec->prec, (int)number->nb_len);
		spec->field_size = PF_MAX(spec->f_width, spec->field_size);
	}
	correct_size_unsigned(spec, number);
	if (spec->type == 'p')
		spec->flags |= PF_HASH;
	ret = print_unsigned_integer(spec, number);
	ft_strdel(&(number->nb_str));
	ft_memdel((void**)&number);
	return (ret);
}

int					print_unsigned_integer(t_ft_pf *spec, t_pf_number *number)
{
	number->nb_str = fill_precision(spec, number);
	if (spec->flags & PF_MINUS)
		return (left_align(spec, number));
	else
		return (right_align(spec, number));
}
