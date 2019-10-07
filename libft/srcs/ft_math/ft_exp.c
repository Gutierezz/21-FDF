/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:47:59 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:48:56 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_math.h"

double	ft_exp(double x)
{
	double	sum;
	double	temp;
	size_t	i;
	int		sign;

	sum = 1;
	temp = 1;
	i = 1;
	sign = 1;
	if (x > 709.f || x < -715.f)
		return (0);
	if (x < 0.0f)
	{
		sign = -1;
		x = -x;
	}
	while (temp > 1e-12)
	{
		temp = temp * x / i++;
		sum += temp;
	}
	return (sign < 0) ? 1 / sum : sum;
}
