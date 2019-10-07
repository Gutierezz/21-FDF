/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:00:43 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/10 20:21:55 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			sign_and_prefix(t_ft_pf *spec, t_pf_number *number)
{
	int		i;

	i = 0;
	if (spec->flags & PF_SPACE)
		i += ft_putchar_fd(' ', spec->fd);
	if (number->sign == 1)
		i += ft_putchar_fd('-', spec->fd);
	if (number->sign == 2)
		i += ft_putchar_fd('+', spec->fd);
	if (spec->flags & PF_HASH && number->base != 10)
	{
		if (spec->type == 'p')
			return ((i += write(spec->fd, "0x", 2)));
		if (number->base == 8 && spec->prec > -1)
			return ((i += write(spec->fd, "0", 1)));
		if (number->value->ui != 0)
		{
			i += ft_putchar_fd('0', spec->fd);
			if (number->base != 8)
				i += ft_putchar_fd(spec->type, spec->fd);
		}
	}
	return (i);
}

int			zero_with_zero_prec(t_ft_pf *spec, t_pf_number *number)
{
	if (spec->prec == 0)
	{
		if ((pf_is_unsigned(spec->type) || spec->type == 'p') &&\
		number->value->ui == 0)
			return (1);
		if ((spec->type == 'd' || spec->type == 'i' || spec->type == 'D') && \
			number->value->i == 0)
			return (1);
	}
	return (0);
}

char		*fill_precision(t_ft_pf *spc, t_pf_number *num)
{
	char	*pr_st;
	char	*nb_str;
	int		i;

	i = 0;
	if (zero_with_zero_prec(spc, num))
	{
		num->nb_len = 0;
		nb_str = ft_strdup("");
	}
	else
		nb_str = ft_ulltoa_base((pf_is_unsigned(spc->type) || \
	spc->type == 'p' ? num->value->ui : (unsigned long long)(PF_ABS(num->value->i))), num->base);
	if (num->base == 16 && (spc->type == 'X'))
	{
		while (nb_str[i])
			(ft_isalpha(nb_str[i])) ? nb_str[i++] -= 32 : nb_str[i++];
		i = 0;
	}
	pr_st = ft_strnew(((int)num->nb_len > spc->prec) ? (int)num->nb_len : spc->prec);
	while (i < (spc->prec - (int)num->nb_len))
		pr_st[i++] = '0';
	ft_strcpy((pr_st + i), nb_str);
	ft_strdel(&nb_str);
	return (pr_st);
}

int			left_align(t_ft_pf *spec, t_pf_number *number)
{
	int		i;
	size_t	prec_len;

	prec_len = ft_strlen(number->nb_str);
	i = 0;
	i += sign_and_prefix(spec, number);
	ft_putstr_fd(number->nb_str, spec->fd);
	i += prec_len;
	while (i < (int)spec->field_size)
		i += ft_putchar_fd(' ', spec->fd);
	return (i);
}

int			right_align(t_ft_pf *spec, t_pf_number *number)
{
	int		i;
	int		prefix;
	size_t	prec_len;

	prec_len = ft_strlen(number->nb_str);
	i = 0;
	prefix = 0;
	if (spec->flags & PF_ZERO)
		i += right_align_with_zero_padding(spec, number, prec_len);
	else
	{
		if (spec->flags & PF_HASH)
			i += (number->base == 8) ? 1 : 2;
		spec->field_size -= (number->sign || spec->flags & PF_SPACE) ? 1 : 0;
		while (i + prec_len < spec->field_size)
			i += ft_putchar_fd(' ', spec->fd);
		prefix = sign_and_prefix(spec, number);
		i += ((spec->flags & PF_HASH)) ? 0 : prefix;
	}
	ft_putstr_fd(number->nb_str, spec->fd);
	i += prec_len;
	return (i);
}
