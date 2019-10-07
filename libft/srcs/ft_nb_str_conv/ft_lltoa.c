/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 16:45:46 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:27:04 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(long long nb)
{
	char	*arr;
	size_t	len;

	if ((len = ft_nblen(nb)) == 0)
		return (NULL);
	arr = ft_strnew(len);
	arr[len] = '\0';
	if (nb < 0)
	{
		if (nb == LLONG_MIN)
		{
			arr[--len] = HEX_STR[-(nb % 10)];
			nb /= 10;
		}
		nb = -nb;
		arr[0] = '-';
	}
	else if (nb == 0)
		arr[--len] = '0';
	while (nb)
	{
		arr[--len] = HEX_STR[nb % 10];
		nb /= 10;
	}
	return (arr);
}
