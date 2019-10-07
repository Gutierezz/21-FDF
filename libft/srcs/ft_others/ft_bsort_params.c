/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsort_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:33:16 by ttroll            #+#    #+#             */
/*   Updated: 2018/12/09 14:32:02 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap_params(char **a, char **b)
{
	char *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			ft_bsort_params(char **arr, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (i < size)
	{
		j = 0;
		while (j < size - i)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
				ft_swap_params(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}
