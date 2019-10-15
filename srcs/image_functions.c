#include "fdf.h"

void	draw_pixel(t_fdf *fdf, int x, int y, int color)
{
	mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
}

void	set_pixel(t_fdf *fdf, int x, int y, int color)
{
	//ft_printf("SET_PIXEL\n");
	if ((x < 0 || x >= WIN_W) || (y < 0 || y >= WIN_H))
		return ;
	*(int *)(fdf->data + (INDEX(x, y, WIN_W) * fdf->bpp)) = color;
	//ft_printf("SET_PIXE_DONE\n");
}

void	clear_image(t_fdf *fdf)
{
	ft_bzero(fdf->map->z_buffer, WIN_W * WIN_H);
	ft_bzero(fdf->data, WIN_W * WIN_H * fdf->bpp);
}

void	put_image(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
