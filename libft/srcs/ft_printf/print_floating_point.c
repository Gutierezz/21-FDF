/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_floating_point.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:06:28 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 11:08:47 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		float_cast(t_val *value, t_ft_pf *spec, va_list ap)
{
	if (spec->size == L)
		value->f = (double)va_arg(ap, long double);
	else
	{
		spec->size = nosize;
		value->f = va_arg(ap, double);
	}
}

void		correct_size_dbl(t_ft_pf *spec, t_pf_number *number, int err)
{
	int		sign;
	char	*tmp;

	sign = ft_getsign_dbl(number->value->f);
	if (spec->flags & PF_SPACE && (spec->flags & PF_PLUS || sign))
		spec->flags = (spec->flags & 0xFB);
	if (spec->flags & PF_ZERO && (spec->flags & PF_MINUS || err))
		spec->flags = (spec->flags & 0xEF);
	if (spec->flags & PF_HASH && (spec->prec > 0 || err))
		spec->flags = (spec->flags & 0xF7);
	if (spec->flags & PF_PLUS && sign)
		spec->flags = (spec->flags & 0xFE);
	if (sign && !err)
	{
		tmp = ft_strdup((number->nb_str + 1));
		ft_strdel(&(number->nb_str));
		number->nb_str = tmp;
		number->nb_len -= 1;
	}
	if (spec->flags & PF_PLUS || sign)
		number->sign = (sign) ? 1 : 2;
}

int			print_floating_point(t_ft_pf *spec, t_pf_number *number)
{
	if (spec->flags & PF_MINUS)
		return (left_align_float(spec, number));
	else
		return (right_align_float(spec, number));
}

int			handle_floating_point(t_ft_pf *spec, va_list ap)
{
	t_pf_number	*number;
	t_val		value;
	int			err;
	int			i;
	int			exp_form;

	i = -1;
	exp_form = (spec->type == 'e' || spec->type == 'E') ? 1 : 0;
	float_cast(&value, spec, ap);
	err = (ft_isnan(value.f) != 0 || ft_isinf(value.f) != 0) ? 1 : 0;
	spec->prec = (spec->prec < 0) ? 6 : spec->prec;
	number = new_number(&value, 0, 10);
	number->nb_str = ft_ftoa(number->value->f, spec->prec, \
		&(number->nb_len), &exp_form);
	number->nb_len += (spec->prec != 0 && !err) ? 1 : 0;
	correct_size_dbl(spec, number, err);
	if (spec->type == 'e' || spec->type == 'E')
		exp_str(spec, number, exp_form);
	if (ft_isupper(spec->type))
	{
		while (number->nb_str[++i])
			number->nb_str[i] = ft_toupper(number->nb_str[i]);
	}
	spec->field_size = PF_MAX(number->nb_len, spec->f_width);
	return (print_floating_point(spec, number));
}
