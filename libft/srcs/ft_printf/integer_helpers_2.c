/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_helpers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:00:18 by ttroll            #+#    #+#             */
/*   Updated: 2019/04/11 11:15:45 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				compare_size_int(int new_index, int old_index)
{
	size_t	arr[9];

	arr[0] = 0;
	arr[1] = sizeof(char);
	arr[2] = sizeof(short);
	arr[3] = sizeof(long);
	arr[4] = sizeof(long double);
	arr[5] = sizeof(int64_t);
	arr[6] = sizeof(size_t);
	arr[7] = sizeof(intmax_t);
	arr[8] = sizeof(ptrdiff_t);
	return (arr[new_index] >= arr[old_index]);
}

int				right_align_with_zero_padding(t_ft_pf *spec, \
	t_pf_number *num, size_t len)
{
	int	ret;

	ret = 0;
	ret += sign_and_prefix(spec, num);
	while (ret + len < spec->field_size)
		ret += ft_putchar_fd('0', spec->fd);
	return (ret);
}

unsigned int	get_int_base(char c)
{
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u' || c == 'U')
		return (10);
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	if (c == 'b')
		return (2);
	if (c == 'o' || c == 'O')
		return (8);
	return (0);
}
