/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:22:06 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/10 21:41:42 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isdivider(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	char	*str;
	char	*ptr;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	while (*(s + i) && ft_isdivider(*(s + i)))
		i++;
	while (*(s + i) && ft_isdivider(*(s + size - 1)))
		size--;
	if (size >= i)
		size -= i;
	if (!(str = ft_strnew(size)))
		return (NULL);
	ptr = str;
	size += i;
	while (i < size)
		*ptr++ = *(s + i++);
	*ptr = '\0';
	return (str);
}
