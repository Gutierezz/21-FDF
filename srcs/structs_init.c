#include "fdf.h"

t_fdf	*fdf_init(t_map *map, char *name)
{
	t_fdf	*fdf;
	char	*title;

	if (!(title = ft_strjoin("FDF - ", name)))
		return (NULL);
	if (!(fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf))))
		return (NULL);
	if ((fdf->mlx = mlx_init()) == NULL)
		fdf_clear(&fdf, MLX_INIT_ERR);
	if ((fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, title)) == NULL)
		fdf_clear(&fdf, WINDOW_INIT_ERR);
	if ((fdf->img = mlx_new_image(fdf->mlx, WIN_W, WIN_H)) == NULL)
		fdf_clear(&fdf, IMAGE_INIT_ERR);
	if ((fdf->data = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_size, &fdf->endian)) == NULL)
		fdf_clear(&fdf, DATA_ADDR_ERR);
	if ((fdf->view = view_init(map)) == NULL)
		fdf_clear(&fdf, MEM_ALLOC_ERR);
	fdf->bpp >>= 3;
	fdf->map = map;
	if (!(map->z_buffer = (int*)ft_memalloc(sizeof(int) * WIN_W * WIN_H)))
		fdf_clear(&fdf, MEM_ALLOC_ERR);
	clear_image(fdf);
	ft_strdel(&title);
	return (fdf);
}

t_map	*map_init(void)
{
	t_map	*map;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->height = 0;
	map->width = 0;
	map->points = NULL;
	map->z_buffer = NULL;
	map->file_data = NULL;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	return (map);
}

t_view	*view_init(t_map *map)
{
	t_view *view;

	if (!(view = (t_view*)ft_memalloc(sizeof(t_view))))
		return (NULL);
	view->proj = PARALLEL;
	view->x_offs = 0;
	view->y_offs = 0;
	view->x_rad = 0.0;
	view->y_rad = 0.0;
	view->z_rad = 0.0;
	view->h_mult = (double)(map->z_max - map->z_min) / (double)(WIN_H);
	view->scale = PF_MIN(WIN_H / map->width, WIN_W / map->height);
	return (view);
}

t_range		range(int min, int max)
{
	t_range	range;

	range.min = min;
	range.max = max;
	return (range);
}
