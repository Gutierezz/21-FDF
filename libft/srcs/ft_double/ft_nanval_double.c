/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nanval_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:14:07 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:14:55 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_nanval_double(int sign)
{
	t_double_un	u;

	u.i = (sign) ? 0xffffffffffffffff : 0x7fffffffffffffff;
	return (u.f);
}
