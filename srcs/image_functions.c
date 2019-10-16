#include "fdf.h"

void	draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
}

void	set_pixel(t_fdf *fdf, int x, int y, int color)
{
	if ((x < 0 || x >= WIN_W) || (y < 0 || y >= WIN_H))
		return ;
	*(int *)(fdf->data + (INDEX(x, y, WIN_W) * fdf->bpp)) = color;
}

void	clear_image(t_fdf *fdf)
{
	int i;
	int size;

	i = -1;
	size = WIN_W * WIN_H;
	while (++i < size)
		fdf->map->z_buff[i] = INT_MIN;
	ft_bzero(fdf->data, WIN_W * WIN_H * fdf->bpp);
}

void	put_image(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
