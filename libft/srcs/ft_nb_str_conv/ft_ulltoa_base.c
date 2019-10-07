/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:46:02 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:01:32 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ulltoa_base(unsigned long long nb, unsigned int base)
{
	char	*arr;
	size_t	len;

	if ((len = ft_unblen_base(nb, base)) == 0)
		return (NULL);
	arr = ft_strnew(len);
	arr[len] = '\0';
	if (nb == 0)
		arr[--len] = '0';
	else
	{
		while (nb)
		{
			len--;
			arr[len] = HEX_STR[nb % base];
			nb /= base;
		}
	}
	return (arr);
}
