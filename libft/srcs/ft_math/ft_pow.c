/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:01:52 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:12:44 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_math.h"

long long	ft_pow(long long nb, unsigned int pow)
{
	long long	res;

	res = 1;
	if (nb == 0)
		return (0);
	if (pow == 0)
		return ((nb < 0) ? -1 : 1);
	while (pow)
	{
		if (pow % 2 == 0)
		{
			pow /= 2;
			nb *= nb;
		}
		else
		{
			pow--;
			res *= nb;
		}
	}
	return (res);
}
