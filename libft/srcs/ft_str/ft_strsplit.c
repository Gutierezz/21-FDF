/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:27:41 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/09 12:42:18 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordscount(char const *s, char c)
{
	size_t	i;
	int		in_word;
	int		words;

	words = 0;
	i = 0;
	in_word = 0;
	if (!s)
		return (-1);
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

static int	ft_getnextlen(char const *s, char c)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_clr(char ***arr, int i)
{
	while (i >= 0)
		ft_strdel(&((*arr)[i--]));
	free(*arr);
	*arr = NULL;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**arr;
	int		w;

	w = ft_wordscount(s, c);
	i = -1;
	if (!s || !(arr = (char**)ft_memalloc(sizeof(char*) * (w + 1))))
		return (NULL);
	j = 0;
	while (++i < w)
	{
		k = 0;
		while (s[j] == c)
			j++;
		if (!(arr[i] = ft_strnew(ft_getnextlen(&s[j], c))) && ft_clr(&arr, i))
			return (NULL);
		while (s[j] && s[j] != c)
			arr[i][k++] = s[j++];
		arr[i][k] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}
