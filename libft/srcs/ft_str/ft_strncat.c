/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:40:05 by ttroll            #+#    #+#             */
/*   Updated: 2018/11/28 22:01:32 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = s1 + ft_strlen(s1);
	i = 0;
	while (i < n && *(s2 + i))
	{
		*(ptr + i) = *(s2 + i);
		i++;
	}
	*(ptr + i) = '\0';
	return (s1);
}
