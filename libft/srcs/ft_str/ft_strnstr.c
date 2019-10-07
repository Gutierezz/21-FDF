/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:45:37 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/10 21:05:15 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (i < n && *(haystack + i))
	{
		j = 0;
		while ((i + j < n) && *(haystack + i + j) == *(needle + j))
		{
			j++;
			if (!*(needle + j))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
