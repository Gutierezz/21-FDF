/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_base_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:32:11 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/10 13:24:32 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_base_digit(char c, int base)
{
	int	index;

	c = ft_tolower(c);
	if (ft_isdigit(c))
		index = c - '0';
	else if (c >= 'a' && c <= 'f')
		index = c - 87;
	else
		return (-1);
	if (index >= base)
		return (-1);
	return (index);
}
