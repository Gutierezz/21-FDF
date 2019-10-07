/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:15:55 by ttroll            #+#    #+#             */
/*   Updated: 2019/09/14 15:58:53 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	fill_leading_byte(int size, wint_t c)
{
	if (size == 4)
		return (0xF0 | (c & 0x07));
	if (size == 3)
		return (0xE0 | (c & 0x0F));
	if (size == 2)
		return (0xC0 | (c & 0x1F));
	else
		return (0x7F & c);
}

static void				fill_bytes(unsigned char *arr, wint_t *c, int size)
{
	while (--size > 0)
	{
		arr[size] = (0x80 | (*c & 0x3F));
		*c >>= 6;
	}
}

static int				err_handle(wint_t c, int fd)
{
	ft_putchar_fd((char)c, fd);
	return (-1);
}

int						ft_putwchar_fd(wint_t c, int fd)
{
	int				size;
	unsigned char	*arr;
	int				i;

	i = 0;
	size = get_wchar_size(c);
	if (size == 1)
		i = ft_putchar_fd((char)c, fd);
	else if (size > (int)MB_CUR_MAX)
		return (err_handle(c, fd));
	else
	{
		arr = (unsigned char*)ft_memalloc(size + 1);
		fill_bytes(arr, &c, size);
		arr[0] = fill_leading_byte(size, c);
		i += write(fd, arr, size);
		free(arr);
	}
	return (i);
}
