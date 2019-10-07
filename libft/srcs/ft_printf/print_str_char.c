/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:13:55 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 13:28:42 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					print_char(t_ft_pf *spec, va_list ap, int is_percent)
{
	int				i;
	unsigned char	symb;
	int				size;

	i = 0;
	if (spec->type == 'C' || (spec->type == 'c' && spec->size == l))
		return (print_wide_char(spec, ap, is_percent));
	size = PF_MAX(spec->f_width, 1);
	if (!is_percent)
		symb = (unsigned char)va_arg(ap, int);
	else
		symb = '%';
	if (spec->flags & PF_MINUS)
	{
		i += ft_putchar_fd(symb, spec->fd);
		while (i < size)
			i += ft_putchar_fd(' ', spec->fd);
		return (i);
	}
	while (i < (size - 1))
		i += ft_putchar_fd((spec->flags & PF_ZERO ? '0' : ' '), spec->fd);
	i += ft_putchar_fd(symb, spec->fd);
	return (i);
}

int					print_string(t_ft_pf *spec, va_list ap)
{
	size_t			size;
	size_t			i;
	char			*str;

	i = 0;
	if (spec->type == 'S' || (spec->type == 's' && spec->size == l))
		return (print_wide_string(spec, ap));
	if ((str = va_arg(ap, char*)) == NULL)
		str = "(null)";
	size = (spec->prec >= 0) ? PF_MIN(ft_strlen(str), (size_t)spec->prec) : \
		ft_strlen(str);
	spec->field_size = PF_MAX(spec->f_width, size);
	if (spec->flags & PF_MINUS || size == spec->field_size)
		return (string_left_align(spec, size, str));
	if (size < spec->field_size)
	{
		while (i + size < spec->field_size)
			i += ft_putchar_fd((spec->flags & PF_ZERO ? '0' : ' '), spec->fd);
		while (i < spec->field_size)
		{
			i += ft_putchar_fd((*str), spec->fd);
			str++;
		}
	}
	return ((int)i);
}

int					print_wide_char(t_ft_pf *spec, va_list ap, int is_percent)
{
	int				len;
	wchar_t			symb;
	int				size;
	int				err;

	err = 0;
	size = PF_MAX(spec->f_width, 1);
	if (!is_percent)
		symb = (wchar_t)va_arg(ap, wint_t);
	else
		symb = L'%';
	len = wide_char_align(spec, &err, size, symb);
	while (err < 0 && --len >= 0)
		ft_putchar_fd('\b', spec->fd);
	return ((err > 0) ? len + err : err);
}

int					print_wide_string(t_ft_pf *spec, va_list ap)
{
	size_t			size;
	wchar_t			*str;
	int				ret;
	int				err;

	err = 0;
	ret = 0;
	if ((str = va_arg(ap, wchar_t*)) == NULL)
		str = L"(null)";
	size = (spec->prec >= 0) ? PF_MIN(ft_strwlen(str), (size_t)spec->prec) : \
	ft_strwlen(str);
	spec->field_size = PF_MAX(spec->f_width, size);
	if (spec->flags & PF_MINUS || size == spec->field_size)
		return (wide_str_left_align(spec, str, size));
	if (size < spec->field_size)
	{
		while (ret + size < spec->field_size)
			ret += ft_putwchar_fd(spec->flags & PF_ZERO ? '0' : ' ', spec->fd);
		err = ft_putwstr_fd(str, size, spec->fd);
		while (err < 0 && --ret >= 0)
			ft_putchar_fd('\b', spec->fd);
	}
	return ((err < 0) ? err : ret + err);
}

int					print_raw_string(t_ft_pf *spec, va_list ap)
{
	size_t			size;
	size_t			i;
	char			*str;

	i = 0;
	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	size = ft_strlen(str);
	spec->field_size = PF_MAX(spec->f_width, size);
	if (spec->flags & PF_MINUS || size == spec->field_size)
		return (printraw_left_align(spec, str));
	if (size < spec->field_size)
	{
		while (i + size < spec->field_size)
			i += ft_putchar_fd((spec->flags & PF_ZERO ? '0' : ' '), spec->fd);
		i += ft_put_rawstr_fd(str, spec->fd);
	}
	return ((int)i);
}
