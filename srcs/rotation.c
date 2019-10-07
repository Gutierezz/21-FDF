#include "fdf.h"

void	x_rotation(t_point *point, double angle)
{
	int	prev_y;

	prev_y = point->y;
	point->y = prev_y * cos(angle) + point->z * sin(angle);
	point->z = -prev_y * sin(angle) + point->z * cos(angle);
}

void	y_rotation(t_point *point, double angle)
{
	int	prev_x;

	prev_x = point->x;
	point->x = prev_x * cos(angle) + point->z * sin(angle);
	point->z = -prev_x * sin(angle) + point->z * cos(angle);
}

void	z_rotation(t_point *point, double angle)
{
	int	prev_x;
	int	prev_y;

	prev_x = point->x;
	prev_y = point->y;
	point->x = prev_x * cos(angle) + prev_y * sin(angle);
	point->y = prev_x * sin(angle) + prev_y * cos(angle);
}

void	rotate_point(t_point *point, t_fdf *fdf)
{
	x_rotation(point, fdf->view->alpha);
	y_rotation(point, fdf->view->beta);
	z_rotation(point, fdf->view->gamma);
}
