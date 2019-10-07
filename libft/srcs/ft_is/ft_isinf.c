/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:30:44 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:30:47 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinf(double x)
{
	t_double_un	u;

	u.f = x;
	if (((u.i >> FT_MANT64_OFFS) & FT_EXP64_MASK) == 0x7ffull)
	{
		if ((u.i & FT_MANT64_MASK) == 0)
			return (u.i & (1ull << FT_SIGN64_OFFS) ? -1 : 1);
	}
	return (0);
}
