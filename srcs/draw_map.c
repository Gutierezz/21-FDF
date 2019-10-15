#include "fdf.h"

// void	swap_coord(t_coord *p1, t_coord *p2)
// {
// 	t_coord tmp;

// 	tmp.x = p1->x;
// 	tmp.y = p1->y;
// 	p1->x = p2->x;
// 	p1->y = p2->y;
// 	p2->x = tmp.x;
// 	p2->y = tmp.y;
// }

// void	wu_line(t_fdf *fdf, t_coord p1, t_coord p2)
// {
// 	t_coord	d;

// 	d.x = (p2.x > p1.x) ? (p2.x - p1.x) : (p1.x - p2.x);
//     d.y = (p2.y > p1.y) ? (p2.y - p1.y) : (p1.y - p2.y);
// 	if (d.x == 0 || d.y == 0)
// 		//draw_simple
// 	if (d.y < d.x)
// 	{
// 		if (p2.x < p1.x)
// 			swap_coord(&p1, &p2);
// 		float grad = (float)d.y / d.x;
// 		float intery = p1.y + grad;
// 		draw_pixel(fdf, p1.x, p1.y , 0xffffff);
// 	}
// 	else
// 	{
// 		if (p2.y < p1.y)
// 			swap_coord(&p1, &p2);
// 	}

// }

void	bres_line(t_fdf *fdf, t_point point1, t_point p2)
{
	t_point	delta;
	t_point step;
	t_point	p1;
	int		err[2];

	p1 = point1;
	step.x = (p1.x < p2.x) ? 1 : -1;
	step.y = (p1.y < p2.y) ? 1 : -1;
	delta.x = abs(p2.x - p1.x);
    delta.y = abs(p2.y - p1.y);
	err[0] = delta.x - delta.y;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		set_pixel(fdf, p1.x, p1.y, 0xFFFFFF);			// ЦВЕТ ПОМЕНЯТЬ
		err[1] = err[0] * 2;
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			p1.x += step.x;
		}
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			p1.y += step.y;
		}
	}
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	ft_printf("draw map\n");
	clear_image(fdf);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
		//	if (fdf->view->proj == ISO && x + 1 != fdf->map->height && y + 1 != fdf->map->width)
		/*		draw_rect(fdf, x, y);*/
	//		else
			{
				if (y + 1 != fdf->map->height)
					bres_line(fdf, fdf->map->points[y][x], fdf->map->points[y + 1][x]);
				if (x + 1 != fdf->map->width)
					bres_line(fdf, fdf->map->points[y][x], fdf->map->points[y][x + 1]);
			}
		}
	}
	put_image(fdf);
}
