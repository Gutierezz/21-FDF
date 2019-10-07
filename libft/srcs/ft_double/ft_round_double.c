/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:08:46 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/03 19:50:35 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_math.h"

void	ft_round_double(double *nb, unsigned precision)
{
	double	rounder;

	rounder = 5.1 * ft_powf_ip(10, -((int)precision + 1));
	if (!ft_getsign_dbl(*nb))
		*nb += rounder;
	else
		*nb -= rounder;
}
