#include "fdf.h"

t_line	line_init(t_point p1, t_point p2)
{
	t_line line;

	line.src_x = p1.x;
	line.dst_x = p2.x;
	line.src_y = p1.y;
	line.dst_y = p2.y;
	line.x = p1.x;
	line.y = p1.y;
	line.dx = abs(p2.x - p1.x);
	line.dy = abs(p2.y - p1.y);
	line.step_x = p1.x < p2.x ? 1 : -1;
	line.step_y = p1.y < p2.y ? 1 : -1;
	line.err_1 = line.dx - line.dy;
	line.progress = 0.0;
	return (line);
}


int		is_visible(int x, int y, int z_val, t_fdf *fdf)
{
	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		if (z_val > fdf->map->z_buff[INDEX(x, y, WIN_W)])
		{
			fdf->map->z_buff[INDEX(x, y, WIN_W)] = z_val;
			return (1);
		}
	}
	return (0);
}

void	bres_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_line	l;

	l = line_init(p1, p2);
	while (l.x != p2.x || l.y != p2.y)
	{
		l.progress = (l.dx > l.dy) ? norm(l.x, l.src_x, l.dst_x) : \
									 norm(l.y, l.src_y, l.dst_y);
		l.z_val = (int)lerp(l.progress, p1.z, p2.z);
		if (is_visible(l.x, l.y, l.z_val, fdf))
			set_pixel(fdf, l.x, l.y, (l.dx > l.dy) ? \
			clerp(range(l.src_x, l.dst_x), l.x, p1.color, p2.color) : \
			clerp(range(l.src_y, l.dst_y), l.y, p1.color, p2.color));
		l.err_2 = l.err_1 * 2;
		if (l.err_2 > -l.dy)
		{
			l.err_1 -= l.dy;
			l.x += l.step_x;
		}
		if (l.err_2 < l.dx)
		{
			l.err_1 += l.dx;
			l.y += l.step_y;
		}
	}
}

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	clear_image(fdf);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			if (y + 1 != fdf->map->height)
				bres_line(fdf, fdf->map->points[y][x], fdf->map->points[y + 1][x]);
			if (x + 1 != fdf->map->width)
				bres_line(fdf, fdf->map->points[y][x], fdf->map->points[y][x + 1]);
		}
	}
	put_image(fdf);
}
