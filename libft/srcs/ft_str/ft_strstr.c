/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:46:02 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/10 16:34:47 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;
	char	*ptr;

	if (!*needle)
		return ((char *)haystack);
	ptr = (char *)haystack;
	len = ft_strlen(needle);
	while ((ptr = ft_strchr(ptr, *needle)))
	{
		if (ft_strncmp(ptr, needle, len) == 0)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
