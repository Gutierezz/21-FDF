/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrawstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:03:19 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 13:15:46 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_put_rawstr_fd(const char *str, int fd)
{
	int		size;
	size_t	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
			ft_putchar_fd(str[i], fd);
		else
			ft_putspecialchar(str[i], fd);
		size++;
		i++;
	}
	if (str[i] == '\0')
		ft_putspecialchar(str[i], fd);
	return (size);
}
