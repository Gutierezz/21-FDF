/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:11:07 by ttroll            #+#    #+#             */
/*   Updated: 2018/11/28 20:49:13 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, int c)
{
	size_t	i;
	int		in_word;
	int		words;

	words = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (!in_word && s[i] != c)
		{
			in_word = 1;
			words++;
		}
		if (in_word && s[i] == c)
			in_word = 0;
		i++;
	}
	return (words);
}
