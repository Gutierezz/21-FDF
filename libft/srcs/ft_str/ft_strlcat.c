/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:19:47 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/09 17:56:07 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int d_len;
	int s_len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	while (*(src + i) && i < ((int)size - d_len - 1))
	{
		*(dst + d_len + i) = *(src + i);
		i++;
	}
	*(dst + d_len + i) = '\0';
	if (d_len < (int)size)
		return (d_len + s_len);
	else
		return (s_len + size - i);
}
