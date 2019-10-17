/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette_gradient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:38:15 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/17 14:53:41 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		palette_color(int z, t_map *map, int color)
{
	double	normal;

	if (color != -1 && map->palette == DEFAULT)
		return (color);
	normal = norm((double)z, (double)map->z_min, (double)map->z_max);
	if (normal < 0.2)
		return (map->colors[0]);
	else if (normal < 0.4)
		return (map->colors[1]);
	else if (normal < 0.6)
		return (map->colors[2]);
	else if (normal < 0.8)
		return (map->colors[3]);
	else
		return (map->colors[4]);
}

int		clerp(t_range coord_range, int pos, int src_color, int dst_color)
{
	int	color;

	color = 0;
	if (src_color == dst_color)
		return (dst_color);
	color |= (int)mapp(pos, coord_range, \
	range((double)(src_color >> 16), (double)(dst_color >> 16))) << 16;
	color |= (int)mapp(pos, coord_range, \
	range((double)(src_color >> 8 & 0xFF), \
	(double)(dst_color >> 8 & 0xFF))) << 8;
	color |= (int)mapp(pos, coord_range, \
	range((double)(src_color & 0xFF), (double)(dst_color & 0xFF)));
	return (color);
}

double	lerp(double norm, double min, double max)
{
	if (min == max)
		return (min);
	return (min * (1.0 - norm) + (max * norm));
}

double	norm(double value, double min, double max)
{
	if (min == max)
		return (1.0);
	return ((value - min) / (max - min));
}

double	mapp(double value, t_range src, t_range dst)
{
	return (lerp(norm(value, src.min, src.max), dst.min, dst.max));
}
