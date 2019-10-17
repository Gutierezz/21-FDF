/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:38:29 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/17 17:53:03 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso_proj(t_point *point, double angle)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = (prev_x - prev_y) * cos(angle);
	point->y = (prev_x + prev_y) * sin(angle) - (point->z);
}

void	scale(t_point *point, t_fdf *fdf)
{
	point->x *= fdf->view->scale;
	point->y *= fdf->view->scale;
	point->z *= fdf->view->h_scale;
}

void	apply_changes(t_fdf *fdf)
{
	int	y;
	int	x;

	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			fdf->map->points[y][x].x = x - fdf->map->width / 2;
			fdf->map->points[y][x].y = y - fdf->map->height / 2;
			fdf->map->points[y][x].z = \
			fdf->map->start_z[INDEX(x, y, fdf->map->width)];
			scale(&fdf->map->points[y][x], fdf);
			rotate(&fdf->map->points[y][x], fdf);
			if (fdf->view->proj == ISO)
				iso_proj(&fdf->map->points[y][x], _2_1_ISO_ANGLE);
			fdf->map->points[y][x].x += fdf->view->x_offs;
			fdf->map->points[y][x].y += fdf->view->y_offs;
		}
	}
}
