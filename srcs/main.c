/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:38:10 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/19 17:20:43 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_palette	handle_args(int ac, char **av, int *fd)
{
	t_palette		palette;

	palette = DEFAULT;
	if (ac < 2 && ac > 3)
		error_message(INPUT_ERR);
	if (ac == 3)
	{
		if (ft_strequ(av[2], "-p1"))
			palette = CITRUS;
		else if (ft_strequ(av[2], "-p2"))
			palette = PINK_PURPLE;
		else if (ft_strequ(av[2], "-p3"))
			palette = MARCEL;
		else
			error_message(PALETTE_ERR);
	}
	if ((*fd = open(av[1], O_RDONLY)) < 0)
		error_message(NO_SUCH_FILE);
	return (palette);
}

int					main(int ac, char **av)
{
	t_fdf		*fdf;
	t_map		*map;
	int			fd;
	int			err;
	t_palette	palette;

	err = 0;
	fd = 0;
	palette = handle_args(ac, av, &fd);
	map = read_map(fd, palette);
	if ((map->width < 2 && map->height < 2) || \
	(err = fill_array(map)))
		map_clear(&map, err ? err : EMPTY_FILE);
	set_colors(map);
	fdf = fdf_init(map, av[1]);
	hook_commands(fdf);
	apply_changes(fdf);
	draw_map(fdf);
	mlx_loop(fdf->mlx);
	fdf_clear(&fdf, 0);
	return (0);
}
