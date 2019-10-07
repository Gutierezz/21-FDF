/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:47:40 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/05 20:51:00 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	number_len(int nb)
{
	size_t len;

	len = 1;
	(nb < 0) ? len++ : len;
	while (nb / 10)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = number_len(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (n <= 0)
	{
		*res = '-';
		*(res + --len) = -1 * (n % (-10)) + '0';
		n /= -10;
	}
	while (n)
	{
		*(res + --len) = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
