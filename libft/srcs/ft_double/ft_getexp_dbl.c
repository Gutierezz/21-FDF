/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getexp_dbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:32:12 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:32:44 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getexp_dbl(double x)
{
	t_double_un	u;
	int			exp;

	u.f = x;
	exp = ((u.i >> FT_MANT64_OFFS) & FT_EXP64_MASK);
	if (exp)
		exp -= FT_EXP64_BIAS;
	else if (u.i & FT_MANT64_MASK)
		exp -= FT_EXP64_BIAS - 1;
	return (exp);
}
