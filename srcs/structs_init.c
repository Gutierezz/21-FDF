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
	if ((fdf->view = view_init(map->width, map->height)) == NULL)
		fdf_clear(&fdf, MEM_ALLOC_ERR);
	fdf->bpp >>= 3;
	clear_image(fdf);
	fdf->map = map;
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
	map->z_arr = NULL;
	map->colors = NULL;
	map->file_data = NULL;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	return (map);
}

t_view	*view_init(int map_w, int map_h)
{
	t_view *view;

	if (!(view = (t_view*)ft_memalloc(sizeof(t_view))))
		return (NULL);
	view->proj = PARALLEL;
	view->x_offs = 0;
	view->y_offs = 0;
	view->alpha = 0;
	view->beta = 0;
	view->gamma = 0;
	view->scale = PF_MIN((WIN_W / map_w / 2), (WIN_H / map_h / 2));
	view->scale = 4;
	return (view);
}

t_point	point(int x, int y, t_map *map)
{
	t_point p;

	p.x = x;
	p.y = y;
	p.z = map->z_arr[INDEX(x, y, map->width)];
	p.color = map->colors[INDEX(x, y, map->width)];
	return (p);
}
