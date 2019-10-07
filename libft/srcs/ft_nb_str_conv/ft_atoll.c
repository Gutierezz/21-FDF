/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:03:19 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/12 14:58:32 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	size_t			i;
	long long		res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] == '-') ? -1 : 1;
	while (i < 20 && ft_isdigit(str[i]))
	{
		if ((res * 10) / 10 == res)
			res = res * 10 + str[i++] - '0';
		else
			return ((sign > 0) ? -1 : 0);
	}
	return ((sign * res));
}
