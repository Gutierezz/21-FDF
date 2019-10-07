/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wchar_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:15:55 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 13:51:48 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_wchar_size(wint_t c)
{
	int		nb_bits;
	char	*nb_str;

	nb_str = ft_ulltoa_base(c, 2);
	nb_bits = ft_strlen(nb_str);
	ft_strdel(&nb_str);
	if (nb_bits <= 7)
		return (1);
	if (nb_bits <= 11)
		return (2);
	if (nb_bits > 11 && nb_bits <= 16)
		return (3);
	else
		return (4);
}
