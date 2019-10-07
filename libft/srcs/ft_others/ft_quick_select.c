/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_select.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:05:22 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/12 13:14:27 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		partition(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	i = start;
	j = end;
	pivot = arr[start + (end - start) / 2];
	while (1)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i >= j)
			return (j);
		if (i < j)
			ft_swap(&arr[i], &arr[j]);
	}
}

int		quick_select(int *arr, int start, int end, int k)
{
	int	middle;

	middle = 0;
	while (1)
	{
		middle = partition(arr, start, end);
		if (middle == k)
			return arr[middle];
		else if (k < middle)
			end = middle;
		else
			start = middle + 1;
	}
}
