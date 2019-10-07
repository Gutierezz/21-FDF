#include "fdf.h"

t_map	*read_map(int fd)
{
	int		brd;
	char	*line;
	char	**line_arr;
	t_map	*map;
	int		err;

	err = 0;
	line = NULL;
	if (!(map = map_init()))
		return (NULL);
	while ((brd = get_next_line2(fd, &line)) > 0)
	{
		if (!(line_arr = ft_strsplit(line, ' ')))
			map_clear(&map, MEM_ALLOC_ERR);
		if ((err = read_line(line_arr, map)))
			break ;
		ft_string_array_del(line_arr);
		line_arr = NULL;
		ft_strdel(&line);
		map->height++;
	}
	(line_arr) ? ft_string_array_del(line_arr) : 0;
	ft_strdel(&line);
	(err) ? map_clear(&map, err) : 0;
	return (map);
}

int	read_line(char **line_arr, t_map *map)
{
	int			i;
	int			width;
	t_pointlst	*node;

	i = -1;
	width = 0;
	while (line_arr[++i])
	{
		width++;
		if (!(node = new_node(line_arr[i])))
			return (READ_MAP_ERR);
		pointlist_add(&map->file_data, node);
		node = NULL;
	}
	if (map->width == 0)
		map->width = width;
	else if (map->width && map->width != width)
		return (DIFF_LINES_LEN);
	return (0);
}

int	fill_arr_from_list(t_map *map)
{
	int			map_size;
	t_pointlst	*ptr;

	map_size = map->width * map->height;
	if (!(map->z_arr = (int*)ft_memalloc(sizeof(int) * map_size)))
		return (MEM_ALLOC_ERR);
	if (!(map->colors = (int*)ft_memalloc(sizeof(int) * map_size)))
		return (MEM_ALLOC_ERR);
	ptr = map->file_data;
	while (ptr && map_size > 0)
	{
		map->z_max = ptr->z > map->z_max ? ptr->z : map->z_max;
		map->z_min = ptr->z < map->z_min ? ptr->z : map->z_min;
		map->z_arr[--map_size] = ptr->z;
		map->colors[map_size] = ptr->color;
		ptr = ptr->next;
	}
	return (0);
}
