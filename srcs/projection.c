#include "fdf.h"

void    iso_proj(t_point *point, double angle)
{
    int prev_x;
    int prev_y;

    prev_x = point->x;
    prev_y = point->y;
    point->x = (prev_x - prev_y) * cos(angle);
    point->y = (prev_x + prev_y) * sin(angle) - (point->z);
}

t_point	project(int x, int y, int z, t_fdf *fdf)
{
	t_point point;

	point.x = x * fdf->view->scale;
	point.y = y * fdf->view->scale;
	point.z = z * fdf->view->scale;
	rotate(&point, fdf);
	if (fdf->view->proj == ISO)
		iso_proj(&point, _2_1_ISO_ANGLE);
	point.x += fdf->view->x_offs;
	point.y += fdf->view->y_offs;
	return (point);
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
			fdf->map->points[y][x] = project(x - fdf->map->width / 2, y - fdf->map->height / 2, fdf->map->start_z[INDEX(x, y, \
			fdf->map->width)], fdf);
			//ft_printf("%d %d %d \n", fdf->map->points[y][x].x, fdf->map->points[y][x].y, fdf->map->points[y][x].z);
		}
	}
}
