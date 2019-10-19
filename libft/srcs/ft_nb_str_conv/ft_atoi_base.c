/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:32:11 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/19 16:13:48 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str, int base)
{
	size_t			i;
	unsigned long	nb;
	int				sign;
	int				pref_offs;

	i = 0;
	nb = 0;
	sign = 1;
	pref_offs = 0;
	while (ft_isspace(str[i]))
		i++;
	if (base == 10 && (str[i] == '+' || str[i] == '-'))
		sign = (str[i++] == '-') ? -1 : 1;
	if (base != 10 && !(pref_offs = ft_skip_prefix(&str[i], base)))
		return (nb);
	i += pref_offs;
	while ((ft_is_base_digit(str[i], base) >= 0))
		nb = nb * base + ft_is_base_digit(str[i++], base);
	return ((int)(nb * sign));
}
