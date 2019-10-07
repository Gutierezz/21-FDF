/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:24:27 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 12:30:58 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr_fd(const wchar_t *str, size_t len, int fd)
{
	int		size;
	size_t	i;
	int		tmp;

	i = 0;
	tmp = 0;
	size = 0;
	while ((size < (int)len) && str[i] != L'\0')
	{
		tmp = (ft_putwchar_fd(str[i], fd));
		if (tmp < 0)
		{
			ft_putchar_fd('\b', fd);
			while (--size >= 0)
				ft_putchar_fd('\b', fd);
			return (tmp);
		}
		size += tmp;
		i++;
	}
	return (size);
}
