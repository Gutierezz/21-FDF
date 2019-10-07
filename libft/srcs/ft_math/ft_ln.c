/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ln.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:01:52 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 20:06:52 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_math.h"

static int		handle_errors(int *n, int *k, double *x, double *sum)
{
	*n = 1;
	*k = 0;
	if (ft_iszero(*x))
	{
		*sum = FT_NEG_INF;
		return (0);
	}
	if (ft_getsign_dbl(*x))
	{
		*sum = FT_PNAN;
		return (0);
	}
	if (*x < 1.0f)
	{
		*x = 1 / *x;
		*sum = 0;
		return (-1);
	}
	if (FLT_ABS((2 - *x)) < 1e-2)
	{
		*sum = FT_LN_2;
		return (0);
	}
	*sum = 0;
	return (1);
}

double			ft_ln(double x)
{
	int		k;
	double	sum;
	double	an;
	int		n;
	int		correct;

	if ((correct = handle_errors(&n, &k, &x, &sum)) == 0)
		return (sum);
	while (x > 2.0f)
	{
		x /= 2.0f;
		k++;
	}
	if (FLT_ABS((2 - x)) < 1e-2)
		return ((k + 1) * FT_LN_2);
	x -= 1.0f;
	an = x;
	while (FLT_ABS(an) > 1e-12)
	{
		sum += an;
		++n;
		an *= -x * (n - 1) / n;
	}
	return (correct * (sum + k * FT_LN_2));
}
