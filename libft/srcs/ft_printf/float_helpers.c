/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:26:13 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 13:16:57 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		exp_str(t_ft_pf *spec, t_pf_number *number, int exp_form)
{
	char	*exp_str;
	size_t	exp_size;
	size_t	i;

	i = 0;
	exp_size = 4;
	exp_size += (spec->prec == 0 && spec->flags & PF_HASH) ? 1 : 0;
	exp_size += (ABS(exp_form) / 100) ? 1 : 0;
	exp_str = ft_strnew(exp_size);
	if (spec->prec == 0 && spec->flags & PF_HASH)
		exp_str[i++] = '.';
	exp_str[i++] = 'e';
	exp_str[i++] = (exp_form < 0) ? '-' : '+';
	exp_form = ABS(exp_form);
	while (exp_size > i)
	{
		exp_str[--exp_size] = HEX_STR[exp_form % 10];
		exp_form /= 10;
	}
	number->nb_str = ft_strjoin_free(&number->nb_str, &exp_str);
	spec->flags = (spec->flags & 0xF7);
	number->nb_len = ft_strlen(number->nb_str);
}

int			left_align_float(t_ft_pf *spec, t_pf_number *number)
{
	int		i;

	i = 0;
	i += sign_and_prefix(spec, number);
	ft_putstr_fd(number->nb_str, spec->fd);
	i += number->nb_len;
	if (spec->prec == 0 && spec->flags & PF_HASH)
		i += ft_putchar_fd('.', spec->fd);
	while (i < (int)spec->field_size)
		i += ft_putchar_fd(' ', spec->fd);
	ft_strdel(&(number->nb_str));
	ft_memdel((void**)&number);
	return (i);
}

int			right_align_float(t_ft_pf *spec, t_pf_number *number)
{
	int		i;

	i = 0;
	if (spec->flags & PF_ZERO)
	{
		i += sign_and_prefix(spec, number);
		while (i + number->nb_len < spec->field_size)
			i += ft_putchar_fd('0', spec->fd);
	}
	else
	{
		if (number->sign || spec->flags & PF_SPACE)
			spec->field_size--;
		while (i + number->nb_len < spec->field_size)
			i += ft_putchar_fd(' ', spec->fd);
		i += sign_and_prefix(spec, number);
	}
	ft_putstr_fd(number->nb_str, spec->fd);
	i += number->nb_len;
	if (spec->prec == 0 && spec->flags & PF_HASH)
		i += ft_putchar_fd('.', spec->fd);
	ft_strdel(&(number->nb_str));
	ft_memdel((void**)&number);
	return (i);
}
