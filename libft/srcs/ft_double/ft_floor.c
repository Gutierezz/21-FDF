/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:44:04 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:47:37 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_floor(double x)
{
	t_double_un	u;
	double		y;
	int			e;

	u.f = x;
	e = u.i >> 52 & 0x7ff;
	if (e >= 0x3ff + 52 || x == 0)
		return (x);
	if (u.i >> 63)
		y = (double)((x - 0x1p52) + 0x1p52 - x);
	else
		y = (double)((x + 0x1p52) - 0x1p52 - x);
	if (e <= 0x3ff - 1)
		return (u.i >> 63 ? -1 : 0);
	if (y > 0)
		return (x + y - 1);
	return (x + y);
}
