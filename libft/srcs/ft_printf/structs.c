/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:17:31 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/10 20:17:41 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ft_pf		*new_spec(const int fd)
{
	t_ft_pf	*new_spec;

	new_spec = (t_ft_pf*)ft_memalloc(sizeof(t_ft_pf));
	new_spec->prec = -1;
	new_spec->fd = fd;
	return (new_spec);
}

t_pf_number	*new_number(t_val *value, size_t nb_len, unsigned int base)
{
	t_pf_number	*new_number;

	new_number = (t_pf_number*)ft_memalloc(sizeof(t_pf_number));
	new_number->value = value;
	new_number->sign = 0;
	new_number->nb_len = nb_len;
	new_number->base = base;
	new_number->nb_str = NULL;
	return (new_number);
}
