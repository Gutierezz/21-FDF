/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:59:53 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/13 12:49:44 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		colored_print(const char *format, size_t *i)
{
	int	ret;

	ret = 0;
	if (ft_strncmp("{red}", &(format[*i]), 5) == 0)
		ret = write(1, ANSI_COLOR_RED, 5);
	else if (ft_strncmp("{green}", &(format[*i]), 7) == 0)
		ret = write(1, ANSI_COLOR_GREEN, 5);
	else if (ft_strncmp("{yellow}", &(format[*i]), 8) == 0)
		ret = write(1, ANSI_COLOR_YELLOW, 5);
	else if (ft_strncmp("{blue}", &(format[*i]), 6) == 0)
		ret = write(1, ANSI_COLOR_BLUE, 5);
	else if (ft_strncmp("{magenta}", &(format[*i]), 9) == 0)
		ret = write(1, ANSI_COLOR_MAGENTA, 5);
	else if (ft_strncmp("{cyan}", &(format[*i]), 6) == 0)
		ret = write(1, ANSI_COLOR_CYAN, 5);
	else if (ft_strncmp("{eoc}", &(format[*i]), 5) == 0)
		ret = write(1, ANSI_COLOR_RESET, 4);
	else
		return (ft_putchar(format[(*i)++]));
	while (format[*i - 1] != '}')
		(*i)++;
	return (ret);
}

int		ft_fprintf(const int fd, const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		f_len;
	int		err_handle;

	f_len = 0;
	i = 0;
	err_handle = 0;
	if (write(fd, "", 0) == -1 || fd < 0)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			f_len += (err_handle = parse_format(format, &i, ap, fd));
			if (err_handle < 0)
				return (err_handle);
		}
		else
			f_len += ft_putchar_fd(format[i++], fd);
	}
	va_end(ap);
	return (f_len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		f_len;
	int		err_handle;

	f_len = 0;
	i = 0;
	err_handle = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			f_len += (err_handle = parse_format(format, &i, ap, 1));
			if (err_handle < 0)
				return (err_handle);
		}
		else if (format[i] == '{')
			f_len += colored_print(format, &i);
		else
			f_len += ft_putchar_fd(format[i++], 1);
	}
	va_end(ap);
	return (f_len);
}

int		handle_type(t_ft_pf *spec, va_list ap)
{
	int	ret;

	ret = 0;
	if (spec->type == 'c' || spec->type == 'C')
		ret = print_char(spec, ap, 0);
	else if (spec->type == '%')
		ret = print_char(spec, ap, 1);
	else if (spec->type == 's' || spec->type == 'S')
		ret = print_string(spec, ap);
	else if (pf_is_unsigned(spec->type) || spec->type == 'p')
		ret = handle_unsigned_integer(spec, ap);
	else if (spec->type == 'd' || spec->type == 'i' || spec->type == 'D')
		ret = handle_signed_integer(spec, ap);
	else if (spec->type == 'r')
		ret = print_raw_string(spec, ap);
	else if (pf_is_float(spec->type))
		ret = handle_floating_point(spec, ap);
	else
		ret = 0;
	return (ret);
}
