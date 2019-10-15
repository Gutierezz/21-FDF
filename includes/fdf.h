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
	MLX_INIT_ERR = 1,
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
	int					min;
	int					max;
}						t_range;

typedef enum			s_proj
{
	PARALLEL,
	ISO
}						t_proj;

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
	t_pointlst			*file_data;
	int					width;
	int					height;
	t_point				**points;
	int					*start_z;
	int					z_min;
	int					z_max;
	int					*z_buffer;
}						t_map;

typedef struct			s_view
{
	t_proj				proj;
	int					scale;
	double				h_mult;
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

t_map	*read_map(int fd);
int		read_line(char **line_arr, t_map *map);
int		fill_arr_from_list(t_map *map);

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
t_point		project(int x, int y, int z, t_fdf *fdf);
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
int			get_color(t_point current, t_point start, t_point end, t_point delta);
double		percent(int start, int end, int current);
int			get_default_color(int z, t_map *map);
int			get_light(int start, int end, double percentage);
double		lerp(double norm, double min, double max);
double		norm(double value, double min, double max);
double		mapp(double value, t_range pixel, t_range comp);


/*
** hook_commands
*/

int			close_window(void *param);
int			key_press(int key, void *param);
void		hook_commands(t_fdf *fdf);

/*
** key_commands
*/

void		move_image(int key, t_fdf *fdf);
void		set_scale(int key, t_fdf *fdf);
void		rotate_image(int key, t_fdf *fdf);
void		set_project_type(int key,t_fdf *fdf);
void		reset_coordinates(t_fdf *fdf);

/*
**	structs_init
*/

t_fdf		*fdf_init(t_map *map, char *name);
t_map		*map_init(void);
t_view		*view_init(t_map *map);
t_point		point(int x, int y, t_map *map);
t_range		range(int min, int max);

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
