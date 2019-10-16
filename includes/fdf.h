#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include "ft_printf.h"
//# include "keys.h"
#include "linux_keys.h"

# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef enum	s_err
{
	INPUT_ERR = 1,
	PALETTE_ERR,
	MLX_INIT_ERR,
	WINDOW_INIT_ERR,
	IMAGE_INIT_ERR,
	DATA_ADDR_ERR,
	READ_MAP_ERR,
	FDF_INIT_ERR,
	MEM_ALLOC_ERR,
	DIFF_LINES_LEN,
	NO_SUCH_FILE,
	EMPTY_FILE
}				t_err;

# define WIN_W			800
# define WIN_H			600
# define MOVE_STEP		10
# define ROTATE_STEP	0.1

#define	CIRLCE_RAD		6.28319

# define PROJECT		1
# define MOVE			2
# define ROTATE			4
# define SCALE			8

# define TRUE_ISO_ANGLE 0.523599
# define _2_1_ISO_ANGLE 0.46373398

# define INDEX(x, y, size) (y * size + x)

typedef	struct			s_range
{
	double					min;
	double					max;
}						t_range;

typedef enum			s_palette
{
	DEFAULT,
	CITRUS,
	PINK_PURPLE,
	MARCEL
}						t_palette;

typedef enum			s_proj
{
	PARALLEL,
	ISO
}						t_proj;

typedef struct			s_line
{
	int 				src_x;
	int					src_y;
	int					dst_x;
	int					dst_y;
	int					dx;
	int					dy;
	int					step_x;
	int					step_y;
	int					x;
	int					y;
	double				progress;
	int					err_1;
	int					err_2;
}						t_line;

typedef struct			s_pointlst
{
	int					z;
	int					color;
	struct s_pointlst	*next;
}						t_pointlst;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_map
{
	t_palette			palette;
	t_pointlst			*file_data;
	int					width;
	int					height;
	t_point				**points;
	int					*start_z;
	int					*colors;
	int					z_min;
	int					z_max;
	int					*z_buff;
}						t_map;

typedef struct			s_view
{
	t_proj				proj;
	int					scale;
	int					h_scale;
	double				x_rad;
	double				y_rad;
	double				z_rad;
	int					x_offs;
	int					y_offs;
}						t_view;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	t_map				*map;
	t_view				*view;
	int					bpp;
	int					line_size;
	int					endian;
}						t_fdf;

/*
** parser
*/

t_map	*read_map(int fd, t_palette palette);
int		read_line(char **line_arr, t_map *map);
int		fill_arr_from_list(t_map *map);
void	set_colors(t_map *map);

/*
** image_functions
*/

void	draw_pixel(t_fdf *fdf, int x, int y, int color);
void	set_pixel(t_fdf *fdf, int x, int y, int color);
void	clear_image(t_fdf *fdf);
void	put_image(t_fdf *fdf);

/*
** projection
*/

void 		iso_proj(t_point *point, double angle);
void		scale(t_point *point, t_fdf *fdf);
void		apply_changes(t_fdf *fdf);

/*
** rotation
*/

void	x_rotation(t_point *point, double angle);
void	y_rotation(t_point *point, double angle);
void	z_rotation(t_point *point, double angle);
void	rotate(t_point *point, t_fdf *fdf);

/*
**	draw_map
*/

t_line		line_init(t_point p1, t_point p2);
void		bres_line(t_fdf *fdf, t_point p1, t_point p2);
void		draw_map(t_fdf *fdf);

/*
**	fill_rect
*/

void	draw_rect(t_fdf *fdf, int x, int y);
void	swap_points(t_point *p1, t_point *p2);
void	fill_triangle(t_point p1, t_point p2, t_point p3, t_fdf *fdf);

/*
**	get_color
*/
int			palette_color(int z, t_map *map, int color);
int			color_lerp(t_line line, int src_color, int dst_color);
double		lerp(double norm, double min, double max);
double		norm(double value, double min, double max);
double		mapp(double value, t_range src, t_range dst);

int	get_light(int start, int end, double percentage); // DELETE


/*
** hook_commands
*/

int			close_window(t_fdf *fdf);
int			key_press(int key, t_fdf *fdf);
void		hook_commands(t_fdf *fdf);

/*
** key_commands
*/

void		move_image(int key, t_fdf *fdf);
void		set_scale(int key, t_fdf *fdf);
void		rotate_image(int key, t_fdf *fdf);
void		set_project_type(int key,t_fdf *fdf);
void		manage_height(int key, t_fdf *fdf);

/*
**	structs_init
*/

t_fdf		*fdf_init(t_map *map, char *name);
t_map		*map_init(t_palette palette);
t_view		*view_init(t_map *map);
int			*init_colors(t_palette palette);
t_range		range(double min, double max);

/*
**	structs_clear
*/

void		map_clear(t_map **map, int err_msg);
void		fdf_clear(t_fdf **fdf, int err_msg);
void		error_message(int err);

/*
**	pointlist
*/

t_pointlst 	*new_node(char *line);
void		pointlist_add(t_pointlst **head, t_pointlst *new);
void		pointlist_clear(t_pointlst **head);
#endif
