/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_char_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:13:33 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 13:27:51 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_left_align(t_ft_pf *spec, size_t size, char *str)
{
	size_t i;

	i = 0;
	while (i < size)
		i += ft_putchar_fd(str[i], spec->fd);
	while (i < spec->field_size)
		i += ft_putchar_fd(' ', spec->fd);
	return ((int)i);
}

int		printraw_left_align(t_ft_pf *spec, char *str)
{
	size_t i;

	i = 0;
	i += ft_put_rawstr_fd(str, spec->fd);
	while (i < spec->field_size)
		i += ft_putchar_fd(' ', spec->fd);
	return ((int)i);
}

int		wide_char_align(t_ft_pf *spec, int *err, int size, wchar_t symb)
{
	int	symb_size;
	int	i;

	i = 0;
	symb_size = (MB_CUR_MAX > 1) ? get_wchar_size(symb) : 1;
	if (spec->flags & PF_MINUS)
	{
		*err = ft_putwchar_fd(symb, spec->fd);
		if (*err > 0)
		{
			while (i + *err < size)
				i += ft_putwchar_fd(L' ', spec->fd);
		}
	}
	else
	{
		while (i < (size - symb_size))
			i += ft_putwchar_fd((spec->flags & PF_ZERO ? '0' : ' '), spec->fd);
		*err = ft_putwchar_fd(symb, spec->fd);
	}
	while (*err < 0 && --symb_size >= 0)
		ft_putchar_fd('\b', spec->fd);
	return (i);
}

int		wide_str_left_align(t_ft_pf *spec, wchar_t *str, size_t size)
{
	int ret;

	ret = 0;
	ret = ft_putwstr_fd(str, size, spec->fd);
	if (ret >= 0)
	{
		while (ret < (int)spec->field_size)
			ret += ft_putwchar_fd(L' ', spec->fd);
	}
	return (ret);
}
