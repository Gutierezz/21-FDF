/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powf_ip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:10:59 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:12:11 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_math.h"

double	ft_powf_ip(double x, int power)
{
	double	res;
	int		sign;

	res = 1;
	sign = (power < 0) ? -1 : 1;
	if (power < 0)
		power = -power;
	if (ft_iszero(x))
		return (0.0f);
	if (power == 0)
		return (1.f);
	while (power)
	{
		if (power % 2 == 0)
		{
			power /= 2;
			x *= x;
		}
		else
		{
			power--;
			res *= x;
		}
	}
	return ((sign < 0) ? 1 / res : res);
}
