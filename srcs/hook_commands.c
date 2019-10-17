/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttroll <ttroll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:37:52 by ttroll            #+#    #+#             */
/*   Updated: 2019/10/17 14:51:14 by ttroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int		close_window(t_fdf *fdf)
{
	fdf_clear(&fdf, 0);
	exit(0);
}

int		key_press(int key, t_fdf *fdf)
{
	if (key == VK_ESC)
	{
		fdf_clear(&fdf, 0);
		exit(0);
	}
	else if (key == VK_UP || key == VK_DOWN || \
	key == VK_RIGHT || key == VK_LEFT)
		move_image(key, fdf);
	else if (key == VK_MINUS || key == VK_PLUS)
		set_scale(key, fdf);
	else if (key == VK_NUM_PLUS || key == VK_NUM_MINUS)
		manage_height(key, fdf);
	else if (key == VK_NUM_1 || key == VK_NUM_2 || key == VK_NUM_3 || \
	key == VK_NUM_4 || key == VK_NUM_5 || key == VK_NUM_6 || key == VK_NUM_7 \
	|| key == VK_NUM_8 || key == VK_NUM_9)
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
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}
