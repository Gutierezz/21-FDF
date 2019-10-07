/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:02:31 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/30 13:35:59 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void			*new_str;

	if (!(new_str = ft_strnew(ft_strlen(s1))))
		return (NULL);
	new_str = (char*)ft_memcpy(new_str, s1, ft_strlen(s1));
	return (new_str);
}
