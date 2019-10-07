/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:49:18 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:50:51 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_ceil(double x)
{
	t_double_un	u;
	int			e;
	double		y;
	double		toint;

	u.f = x;
	toint = 1 / 2.20e-16;
	e = u.i >> 52 & 0x7ff;
	if (e >= 0x3ff + 52 || x == 0)
		return (x);
	if (u.i >> 63)
		y = x - toint + toint - x;
	else
		y = x + toint - toint - x;
	if (e <= 0x3ff - 1)
		return (u.i >> 63 ? -0.0 : 1);
	if (y < 0)
		return (x + y + 1);
	return (x + y);
}
