/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_gapjoin_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:06:50 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:07:43 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_gapjoin_free(char **s1, char **s2, char gap)
{
	char	*catstr;

	catstr = NULL;
	catstr = ft_str_gapjoin(*s1, *s2, gap);
	ft_strdel(s1);
	ft_strdel(s2);
	return (catstr);
}
