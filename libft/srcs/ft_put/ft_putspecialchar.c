/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putspecialchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:14:41 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/12 13:14:45 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putspecialchar(unsigned char c, int fd)
{
	char	*tmp;

	if (c == '\a')
		ft_putstr_fd("\\a", fd);
	else if (c == '\b')
		ft_putstr_fd("\\b", fd);
	else if (c == '\t')
		ft_putstr_fd("\\t", fd);
	else if (c == '\n')
		ft_putstr_fd("\\n", fd);
	else if (c == '\v')
		ft_putstr_fd("\\v", fd);
	else if (c == '\f')
		ft_putstr_fd("\\f", fd);
	else if (c == '\r')
		ft_putstr_fd("\\r", fd);
	else if (c == '\0')
		ft_putstr_fd("\\0", fd);
	else
	{
		ft_putstr_fd("\\x", fd);
		(c < 16) ? ft_putchar_fd('0', fd) : c;
		ft_putstr_fd((tmp = ft_ulltoa_base((unsigned long long)c, 16)), fd);
		ft_strdel(&tmp);
	}
}
