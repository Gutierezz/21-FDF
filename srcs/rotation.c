/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:38:37 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/19 11:55:10 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rotation(t_point *point, double angle)
{
	int	old_y;

	old_y = point->y;
	point->y = old_y * cos(angle) + point->z * sin(angle);
	point->z = -old_y * sin(angle) + point->z * cos(angle);
}

void	y_rotation(t_point *point, double angle)
{
	int	old_x;

	old_x = point->x;
	point->x = old_x * cos(angle) + point->z * sin(angle);
	point->z = -old_x * sin(angle) + point->z * cos(angle);
}

void	z_rotation(t_point *point, double angle)
{
	int	old_x;
	int	old_y;

	old_x = point->x;
	old_y = point->y;
	point->x = old_x * cos(angle) - old_y * sin(angle);
	point->y = old_x * sin(angle) + old_y * cos(angle);
}

void	rotate(t_point *point, t_fdf *fdf)
{
	x_rotation(point, fdf->view->x_rad);
	y_rotation(point, fdf->view->y_rad);
	z_rotation(point, fdf->view->z_rad);
}
