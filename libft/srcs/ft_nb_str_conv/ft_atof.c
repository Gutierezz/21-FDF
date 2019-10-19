/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:03:19 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/19 16:13:10 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	initialize(int *sign, double *pos, size_t *i, double *res)
{
	*sign = 1;
	*pos = 0.1;
	*i = 0;
	*res = 0;
}

double		ft_atof(const char *str)
{
	double		res;
	long long	integer;
	size_t		i;
	double		pos;
	int			sign;

	initialize(&sign, &pos, &i, &res);
	integer = ft_atoll(str);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] == '-') ? -1 : 1;
	i += ft_nblen(integer);
	if (sign < 0 && integer != 0)
		i--;
	if (str[i] && str[i] == '.')
	{
		while (ft_isdigit(str[++i]))
		{
			res += (pos * (str[i] - '0'));
			pos /= 10;
		}
	}
	res += (double)ABS(integer);
	return ((sign < 0) ? -res : res);
}
