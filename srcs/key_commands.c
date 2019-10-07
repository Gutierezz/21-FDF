#include "fdf.h"

void		move_image(int key, t_fdf *fdf)
{
	if (key == VK_UP)
		fdf->view->y_offs -= MOVE_STEP;
	else if (key == VK_DOWN)
		fdf->view->y_offs += MOVE_STEP;
	else if (key == VK_RIGHT)
		fdf->view->x_offs += MOVE_STEP;
	else if (key == VK_LEFT)
		fdf->view->x_offs -= MOVE_STEP;
	draw_map(fdf);
}

void		set_scale(int key, t_fdf *fdf)
{
	if (key == VK_NUM_MINUS || key == VK_MINUS)
		fdf->view->scale -= (fdf->view->scale > 1) ?  1 : 0;
	else if (key == VK_NUM_PLUS || key == VK_PLUS)
		fdf->view->scale += (fdf->view->scale < 50) ? 1 : 0;
	draw_map(fdf);
}

void		rotate_image(int key, t_fdf *fdf)
{
	if (key == VK_NUM_2)
	 	fdf->view->alpha += ROTATE_STEP;
	else if (key == VK_NUM_8)
	 	fdf->view->alpha -= ROTATE_STEP;
	else if (key == VK_NUM_6)
	 	fdf->view->beta += ROTATE_STEP;
	else if (key == VK_NUM_4)
	 	fdf->view->beta -= ROTATE_STEP;
	else if (key == VK_NUM_1 || key == VK_NUM_3)
	 	fdf->view->gamma += ROTATE_STEP;
	else if (key == VK_NUM_7 || key == VK_NUM_9)
	 	fdf->view->gamma -= ROTATE_STEP;
	draw_map(fdf);
}

void		set_project_type(int key,t_fdf *fdf)
{
	fdf->view->alpha = 0;
	fdf->view->beta = 0;
	fdf->view->gamma = 0;
	if (key == VK_I)
		fdf->view->proj = ISO;
	else if (key == VK_P)
		fdf->view->proj = PARALLEL;
	draw_map(fdf);
}
