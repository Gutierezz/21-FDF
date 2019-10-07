/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:15:13 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:17:30 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	modf_helper(t_double_un *u, double x, int e, double *iptr)
{
	uint64_t	mask;

	mask = -1ULL >> 12 >> e;
	if (e >= 52)
	{
		*iptr = x;
		if (e == 0x400 && u->i << 12 != 0)
			return (x);
		u->i &= 1ULL << 63;
		return (u->f);
	}
	if (e < 0 || ((u->i & mask) == 0))
	{
		if ((u->i & mask) == 0)
			*iptr = x;
		if (e < 0)
			*iptr = u->f;
		u->i &= 1ULL << 63;
		return ((e < 0) ? x : u->f);
	}
	u->i &= ~mask;
	*iptr = u->f;
	return (x - u->f);
}

double			ft_modf(double x, double *iptr)
{
	t_double_un	u;
	int			e;

	u.f = x;
	e = (int)(u.i >> 52 & 0x7ff) - 0x3ff;
	return (modf_helper(&u, x, e, iptr));
}
