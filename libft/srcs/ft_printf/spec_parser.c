/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:38:12 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 15:25:20 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_format(const char *format, size_t *i, va_list ap, int fd)
{
	t_ft_pf			*spec;
	int				ret;
	int				err_code;

	ret = 0;
	spec = new_spec(fd);
	err_code = get_params(format, i, spec, ap);
	if (err_code == 0)
	{
		ret = handle_type(spec, ap);
		(*i)++;
	}
	else
	{
		while (format[*i] != 0 && format[*i] != '%')
		{
			ret += ft_putchar_fd(format[*i], spec->fd);
			(*i)++;
		}
	}
	ft_memdel((void**)&spec);
	return (ret);
}

int		get_params(const char *fmt, size_t *i, t_ft_pf *spec, va_list ap)
{
	unsigned int	old_size;

	while (fmt[*i] && !pf_is_type(fmt[*i]))
	{
		if (pf_is_flag(fmt[*i]))
		{
			get_flag(fmt[*i], spec);
			(*i)++;
		}
		else if (ft_isdigit(fmt[*i]) || fmt[*i] == '*' || fmt[*i] == '.')
			get_width_or_prec(fmt, i, spec, ap);
		else if (pf_is_size(fmt[*i]))
		{
			old_size = spec->size;
			get_size(fmt, i, spec);
			if (compare_size_int(spec->size, old_size) == 0)
				spec->size = old_size;
		}
		else
			return (1);
	}
	if (fmt[*i] && pf_is_type(fmt[*i]))
		spec->type = fmt[*i];
	return ((spec->type != '\0') ? 0 : 1);
}

void	get_flag(char c, t_ft_pf *spec)
{
	spec->flags = (c == '+') ? (spec->flags | PF_PLUS) : spec->flags;
	spec->flags = (c == '-') ? (spec->flags | PF_MINUS) : spec->flags;
	spec->flags = (c == ' ') ? (spec->flags | PF_SPACE) : spec->flags;
	spec->flags = (c == '#') ? (spec->flags | PF_HASH) : spec->flags;
	spec->flags = (c == '0') ? (spec->flags | PF_ZERO) : spec->flags;
}

void	get_width_or_prec(const char *fmt, size_t *i, t_ft_pf *spec, va_list ap)
{
	int				width;
	int				precision;

	precision = -1;
	width = 0;
	if (fmt[*i] == '.')
	{
		(*i)++;
		precision = ft_atoi(&(fmt[*i]));
		spec->prec = (fmt[*i] == '*') ? va_arg(ap, int) : precision;
	}
	else
	{
		width = (fmt[*i] == '*') ? va_arg(ap, int) : ft_atoi(&(fmt[*i]));
		if (fmt[*i] == '*' && width < 0)
			spec->flags |= PF_MINUS;
		spec->f_width = (width < 0) ? -width : width;
	}
	if (fmt[*i] == '*')
		(*i)++;
	else
	{
		while (ft_isdigit(fmt[*i]))
			(*i)++;
	}
}

void	get_size(const char *format, size_t *i, t_ft_pf *spec)
{
	if (format[*i] == 'l')
	{
		spec->size = (format[*i + 1] == 'l') ? ll : l;
		if (spec->size == ll)
			(*i)++;
	}
	else if (format[*i] == 'h')
	{
		spec->size = (format[*i + 1] == 'h') ? hh : h;
		if (spec->size == hh)
			(*i)++;
	}
	else
	{
		if (format[*i] == 'z')
			spec->size = z;
		if (format[*i] == 'L')
			spec->size = L;
		if (format[*i] == 'j')
			spec->size = j;
		if (format[*i] == 't')
			spec->size = t;
	}
	(*i)++;
}
