#include "fdf.h"

// void	draw_rect(t_fdf *fdf, int x, int y)
// {
// 	t_point	p1;
// 	t_point p2;
// 	t_point p3;
// 	t_point p4;

// 	ft_printf("draw rect!\n");
// 	p1 = proj(point(x, y, fdf->map), fdf);
// 	p2 = proj(point(x + 1, y, fdf->map), fdf);
// 	p3 = proj(point(x , y + 1, fdf->map), fdf);
// 	p4 = proj(point(x + 1, y + 1, fdf->map), fdf);
// 	fill_triangle(p1, p2, p3, fdf);
// 	fill_triangle(p2, p3, p4, fdf);
// 	bres_line(fdf, p1, p2);
// 	bres_line(fdf, p1, p3);
// }

// void	swap_points(t_point *p1, t_point *p2)
// {
// 	t_point tmp;
// 	tmp.x = p1->x;
// 	tmp.y = p1->y;
// 	tmp.z = p1->z;
// 	tmp.color = p1->color;
// 	p1->x = p2->x;
// 	p1->y = p2->y;
// 	p1->z = p2->z;
// 	p1->color = p2->color;
// 	p2->x = tmp.x;
// 	p2->y = tmp.y;
// 	p2->z = tmp.z;
// 	p2->color = tmp.color;
// }

// void	fill_triangle(t_point p1, t_point p2, t_point p3, t_fdf *fdf)
// {
// 	int	xa;
// 	int	xb;
// 	int	za;
// 	int	zb;
// 	int	y;
// 	int z;
// 	int x;

// //	ft_printf("fiil triangle\n");
// 	y = p1.y;
// 	if (p2.y < p1.y)
// 		swap_points(&p1, &p2);
// 	if (p3.y < p1.y)
// 		swap_points(&p1, &p3);
// 	if (p3.y < p2.y)
// 		swap_points(&p3, &p2);
// 	// ft_printf("p1 x:%d y:%d z:%d\n", p1.x, p1.y, p1.z);
// 	// ft_printf("p2 x:%d y:%d z:%d\n", p2.x, p2.y, p2.z);
// 	// ft_printf("p3 x:%d y:%d z:%d\n", p3.x, p3.y, p3.z);
// 	if (p1.y == p2.y || p1.y == p3.y)
// 	{
// 		p2.x = p3.x;
// 		p2.y = p3.y;
// 	}
// 	while (y < p3.y)
// 	{
// 		xa = p1.x + (p2.x - p1.x) * ((y - p1.y) / (p2.y - p1.y));
// 		xb = p1.x + (p3.x - p1.x) * ((y - p1.y) / (p3.y - p1.y));
// 		za = p1.z + (p2.z - p1.z) * ((y - p1.y) / (p2.y - p1.y));
// 		zb = p1.z + (p2.z - p1.z) * ((y - p1.y) / (p3.y - p1.y));
// 		x = xa;
// 		while (x < xb)
// 		{
// 			z = za + (zb - za * ((x - xa) / (xb - xa)));
// 			//ft_printf("z : %d\n", z);
// 			if (z > fdf->map->z_buffer[INDEX(x, y, WIN_W)])
// 			{
// 				fdf->map->z_buffer[INDEX(x, y, WIN_W)] = z;
// 				//draw_pixel(fdf, x, y, get_default_color(z , fdf->map));
// 			}
// 			x++;
// 		}
// 	y++;
// 	}
// }
