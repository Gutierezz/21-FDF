/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:41:31 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/10 16:33:49 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	size;
	size_t	length;

	length = ft_strlen(src);
	size = (len > length) ? length : len;
	if (size != len)
		ft_bzero(dst + size, len - size);
	ft_memcpy(dst, src, size);
	return (dst);
}
