/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:38:49 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/17 14:39:30 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*fdf_init(t_map *map, char *name)
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
	if ((fdf->data = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->line_size, \
		&fdf->endian)) == NULL)
		fdf_clear(&fdf, DATA_ADDR_ERR);
	if ((fdf->view = view_init(map)) == NULL)
		fdf_clear(&fdf, MEM_ALLOC_ERR);
	fdf->bpp >>= 3;
	fdf->map = map;
	if (!(map->z_buff = (int*)ft_memalloc(sizeof(int) * WIN_W * WIN_H)))
		fdf_clear(&fdf, MEM_ALLOC_ERR);
	clear_image(fdf);
	ft_strdel(&title);
	return (fdf);
}

t_map		*map_init(t_palette palette)
{
	t_map	*map;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->height = 0;
	map->width = 0;
	map->palette = palette;
	map->points = NULL;
	map->z_buff = NULL;
	map->start_z = NULL;
	if (!(map->colors = init_colors(palette)))
		return (NULL);
	map->file_data = NULL;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	return (map);
}

t_view		*view_init(t_map *map)
{
	t_view	*view;

	if (!(view = (t_view*)ft_memalloc(sizeof(t_view))))
		return (NULL);
	view->proj = PARALLEL;
	view->x_offs = WIN_W / 2;
	view->y_offs = WIN_H / 2;
	view->x_rad = 0.0;
	view->y_rad = 0.0;
	view->z_rad = 0.0;
	view->scale = PF_MIN(WIN_H / map->width, WIN_W / map->height);
	view->h_scale = (map->z_max == map->z_min) ? 1 : \
		view->scale / (map->z_max - map->z_min) + 1;
	return (view);
}

t_range		range(double min, double max)
{
	t_range	range;

	range.min = min;
	range.max = max;
	return (range);
}

int			*init_colors(t_palette palette)
{
	int		*colors;

	if (!(colors = (int*)ft_memalloc(sizeof(int) * 5)))
		return (NULL);
	if (palette == CITRUS || palette == DEFAULT)
	{
		colors[0] = (palette == CITRUS) ? 0x53bf14 : 0x726edb;
		colors[1] = (palette == CITRUS) ? 0xbbf50d : 0xdb6e6e;
		colors[2] = (palette == CITRUS) ? 0xffaa01 : 0xdb6ecb;
		colors[3] = (palette == CITRUS) ? 0xfe5900 : 0x6edb91;
		colors[4] = (palette == CITRUS) ? 0xfaea01 : 0xcfdb6e;
	}
	if (palette == PINK_PURPLE || palette == MARCEL)
	{
		colors[0] = (palette == MARCEL) ? 0xed5565 : 0x5732a8;
		colors[1] = (palette == MARCEL) ? 0xf8ac59 : 0x9830b7;
		colors[2] = (palette == MARCEL) ? 0xc1e5ef : 0xed5eb7;
		colors[3] = (palette == MARCEL) ? 0x1799c6 : 0xef87a9;
		colors[4] = (palette == MARCEL) ? 0x08597d : 0xffbbb1;
	}
	return (colors);
}
