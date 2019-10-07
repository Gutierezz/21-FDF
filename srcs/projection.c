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

t_point	proj(t_point point, t_fdf *fdf)
{
	point.x *= fdf->view->scale;
	point.y *= fdf->view->scale;
	point.z *= fdf->view->scale;
	point.x -= (fdf->map->width * fdf->view->scale) / 2;
	point.y -= (fdf->map->height * fdf->view->scale) / 2;
	rotate_point(&point, fdf);
	if (fdf->view->proj == ISO)
		iso_proj(&point, _2_1_ISO_ANGLE);
	point.x += WIN_W / 2 + fdf->view->x_offs;
	point.y += (WIN_H + fdf->map->height * fdf->view->scale) / 2 + fdf->view->y_offs;
	return (point);
}
