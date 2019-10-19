/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_array_del.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:02:37 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/19 16:59:46 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_string_array_del(char **arr)
{
	int		i;

	i = -1;
	if (arr)
	{
		while (arr[++i])
			ft_strdel(&arr[i]);
		ft_memdel((void**)&arr);
	}
}
