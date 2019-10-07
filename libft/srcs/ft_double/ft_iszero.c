/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iszero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:27:54 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:28:18 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iszero(double x)
{
	t_double_un	u;

	u.f = x;
	if (((u.i >> FT_MANT64_OFFS) & FT_EXP64_MASK) == 0x0)
	{
		if ((u.i & FT_MANT64_MASK) == 0)
			return (u.i & (1ull << FT_SIGN64_OFFS) ? -1 : 1);
	}
	return (0);
}
