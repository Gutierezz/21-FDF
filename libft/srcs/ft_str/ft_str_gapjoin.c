/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_gapjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 19:06:50 by ttroll            #+#    #+#             */
/*   Updated: 2019/03/31 19:07:43 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*helper(const char *str, char gap)
{
	size_t		i;
	char		*new_str;

	i = 0;
	if (!(new_str = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	while (*(str + i))
	{
		*(new_str + i) = *(str + i);
		i++;
	}
	*(new_str + i++) = gap;
	*(new_str + i) = '\0';
	return (new_str);
}

char		*ft_str_gapjoin(const char *s1, const char *s2, char gap)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	if (!s1)
		return (helper(s2, gap));
	if (!s2)
		return (helper(s1, gap));
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2)))
		return (NULL);
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	if (i > 0 && *(str +  i - 1) != gap)
		*(str + i++) = gap;
	while (*(s2 + j))
		*(str + i++) = *(s2 + j++);
	*(str + i++) = gap;
	*(str + i) = '\0';
	return (str);
}
