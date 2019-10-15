#include "fdf.h"

void	map_clear(t_map **map, int err_msg)
{
	int y;

	y = -1;
	ft_printf("MAP_CLEAR!\n");
	if (*map)
	{
		while (++y < (*map)->height)
			ft_memdel((void**)&(*map)->points[y]);
		ft_memdel((void**)&(*map)->points);
		ft_memdel((void**)&(*map)->start_z);
		pointlist_clear(&(*map)->file_data);
		ft_memdel((void**)map);
	}
	if (err_msg)
		error_message(err_msg);
}

void	fdf_clear(t_fdf **fdf, int err_msg)
{
	ft_printf("FDF_CLEAR!\n");
	if (*fdf)
	{
		map_clear(&(*fdf)->map, 0);
		if ((*fdf)->img)
			mlx_destroy_image((*fdf)->mlx, (*fdf)->img);
		if ((*fdf)->win)
			mlx_destroy_window((*fdf)->mlx, (*fdf)->win);
		//ft_memdel((void**)&(*fdf)->data);
		//ft_memdel((void**)&(*fdf)->img);
		ft_memdel((void**)&(*fdf)->view);
		ft_memdel((void**)&(*fdf)->mlx);
		ft_memdel((void**)fdf);
	}
	if (err_msg)
		error_message(err_msg);
}

void		error_message(int err)
{
	ft_fprintf(2, "Error : %d\n", err);
	exit (err);
}
