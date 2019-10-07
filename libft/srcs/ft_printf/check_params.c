/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:32:11 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/10 13:24:32 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_is_flag(char c)
{
	char	*str;

	str = "+- #0";
	return ((ft_strchr(str, c) != NULL));
}

int		pf_is_size(char c)
{
	return ((ft_strchr("Llhjzt", c) != NULL));
}

int		pf_is_type(char c)
{
	return ((ft_strchr("%cCrsSpdDioOuUbxXfFeE", c) != NULL));
}

int		pf_is_unsigned(char c)
{
	return ((ft_strchr("oOuUbxX", c) != NULL));
}

int		pf_is_float(char c)
{
	return ((ft_strchr("fFeE", c) != NULL));
}
