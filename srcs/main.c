#include  "fdf.h"

int main(int ac, char **av)
{
	t_fdf	*fdf;
	t_map	*map;
	int 	fd;
	int		err;

	err = 0;
	if (ac != 2)
	{
		ft_printf("Usage: ./fdf file_name");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error_message(NO_SUCH_FILE);
	map = read_map(fd);
	if ((err = fill_arr_from_list(map)))
		map_clear(&map, err);
	fdf = fdf_init(map, av[1]);
	hook_commands(fdf);
	apply_changes(fdf);
	draw_map(fdf);
	mlx_loop(fdf->mlx);
	fdf_clear(&fdf, 0);
	return (0);
}
