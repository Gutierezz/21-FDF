/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:03:19 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:59:43 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_base(const char *str, int base)
{
	int	i;
	int	len;
	int	cnt;

	cnt = 0;
	len = 0;
	i = 0;
	if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	if ((base == 2 || base == 8 || base == 16))
	{
		if (ft_skip_prefix(str, base))
			i += ft_skip_prefix(str, base);
		else
			return (0);
	}
	len = ft_strlen(&str[i]);
	while (str[i] && (ft_is_base_digit(str[i++], base) >= 0))
		cnt++;
	return ((cnt == len) ? 1 : 0);
}
