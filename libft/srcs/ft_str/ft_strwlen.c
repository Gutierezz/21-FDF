/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:43:12 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 13:43:05 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strwlen(const wchar_t *str)
{
	size_t			ret;
	const wchar_t	*ptr;

	ret = 0;
	ptr = str;
	while (*ptr != L'\0')
	{
		ret += get_wchar_size((wint_t)(*ptr));
		ptr++;
	}
	return (ret);
}
