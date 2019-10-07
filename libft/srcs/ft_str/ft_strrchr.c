/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:59:23 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/10 16:33:21 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	char	*occur;

	occur = NULL;
	while ((tmp = ft_strchr(s, c)))
	{
		s = tmp + 1;
		occur = tmp;
		if (c == 0)
			break ;
	}
	return (occur);
}
