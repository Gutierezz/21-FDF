#include "fdf.h"

void	map_clear(t_map **map, int err_msg)
{
	int y;

	y = -1;
	ft_printf("MAP_CLEAR!\n");
	if (*map)
	{
		if ((*map)->points)
		{
			while (++y < (*map)->height)
				ft_memdel((void**)&(*map)->points[y]);
			ft_memdel((void**)&(*map)->points);
		}
		ft_printf("MAP_CLEAR2!\n");
		if ((*map)->start_z)
			ft_memdel((void**)&(*map)->start_z);
		ft_printf("MAP_CLEAR3!\n");
		pointlist_clear(&(*map)->file_data);
		ft_printf("MAP_CLEAR4!\n");
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
	if (err == INPUT_ERR)
		ft_fprintf(2, "Usage: ./fdf file_name OPTIONAL : palette('-p[1-3]')");
	if (err == PALETTE_ERR)
		ft_fprintf(2, "Error : wrong palette parameter\n");
	if (err == MLX_INIT_ERR)
		ft_fprintf(2, "Error : MLX initialization failed\n");
	if (err == WINDOW_INIT_ERR)
		ft_fprintf(2, "Error : MLX Window initialization failed\n");
	if (err == IMAGE_INIT_ERR)
		ft_fprintf(2, "Error : MLX Image initialization failed\n");
	if (err == DATA_ADDR_ERR)
		ft_fprintf(2, "Error : MLX Image Data Adress failed\n");
	if (err == READ_MAP_ERR)
		ft_fprintf(2, "Error : Map reading failed\n");
	if (err == FDF_INIT_ERR)
		ft_fprintf(2, "Error : structure initialization failed\n");
	if (err == MEM_ALLOC_ERR)
		ft_fprintf(2, "Error : Memory allocation failed\n");
	if (err == DIFF_LINES_LEN)
		ft_fprintf(2, "Error : Map has lines with different length\n");
	if (err == NO_SUCH_FILE)
		ft_fprintf(2, "Error : Map doesn't exist\n");
	if (err ==	EMPTY_FILE)
		ft_fprintf(2, "Error : Map is empty\n");
	exit (err);
}
