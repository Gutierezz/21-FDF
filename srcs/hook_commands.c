#include "fdf.h"

int		close_window(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	fdf_clear(&fdf, 0);
	exit(0);
}

int		key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	ft_printf("key %d\n", key);
	if (key == VK_ESC)
	{
		fdf_clear(&fdf, 0);
		exit (0);
	}
	else if (key == VK_UP || key == VK_DOWN || key == VK_RIGHT || key == VK_LEFT)
		move_image(key, fdf);
	else if (key == VK_MINUS || key == VK_PLUS || key == VK_NUM_PLUS || key == VK_NUM_MINUS)
		set_scale(key, fdf);
	else if (key == VK_NUM_1 || key == VK_NUM_2 || key == VK_NUM_3 || key == VK_NUM_4 ||
		key == VK_NUM_5 || key == VK_NUM_6 || key == VK_NUM_7 || key == VK_NUM_8 ||
		key == VK_NUM_9)
		rotate_image(key, fdf);
	else if (key == VK_I || key == VK_P)
		set_project_type(key, fdf);
	apply_changes(fdf);
	draw_map(fdf);
	return (0);
}

void	hook_commands(t_fdf *fdf)
{
	// mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	// mlx_hook(fdf->win, 4, 0, mouse_release, fdf);
	// mlx_hook(fdf->win, 4, 0, mouse_move, fdf);
	//mlx_hook(fdf->win, 2, (1L<<0), key_press, fdf);
	mlx_key_hook(fdf->win, key_press, fdf);
	mlx_hook(fdf->win, 17, (1L<<17), close_window, fdf);
}
