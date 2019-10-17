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
}

void		set_scale(int key, t_fdf *fdf)
{
	if (key == VK_NUM_MINUS || key == VK_MINUS)
		fdf->view->scale -= (fdf->view->scale > 1) ?  1 : 0;
	else if (key == VK_NUM_PLUS || key == VK_PLUS)
		fdf->view->scale += (fdf->view->scale < 100) ? 1 : 0;
}

void		rotate_image(int key, t_fdf *fdf)
{
	(void)key;
	if (key == VK_NUM_2)
	 	fdf->view->y_rad += ROTATE_STEP;
	else if (key == VK_NUM_8)
	 	fdf->view->y_rad -= ROTATE_STEP;
	else if (key == VK_NUM_6)
	 	fdf->view->z_rad += ROTATE_STEP;
	else if (key == VK_NUM_4)
	 	fdf->view->z_rad -= ROTATE_STEP;
	else if (key == VK_NUM_1 || key == VK_NUM_3)
	 	fdf->view->x_rad += ROTATE_STEP;
	else if (key == VK_NUM_7 || key == VK_NUM_9)
	 	fdf->view->x_rad -= ROTATE_STEP;
	// if (fdf->view->x_rad > CIRLCE_RAD || fdf->view->x_rad < -CIRLCE_RAD)
	// 	fdf->view->x_rad -= fdf->view->x_rad > CIRLCE_RAD ? CIRLCE_RAD : -CIRLCE_RAD;
	// if (fdf->view->y_rad > CIRLCE_RAD || fdf->view->y_rad < -CIRLCE_RAD)
	// 	fdf->view->y_rad -= fdf->view->y_rad > CIRLCE_RAD ? CIRLCE_RAD : -CIRLCE_RAD;
	// if (fdf->view->z_rad > CIRLCE_RAD || fdf->view->z_rad < -CIRLCE_RAD)
	// 	fdf->view->z_rad -= fdf->view->z_rad > CIRLCE_RAD ? CIRLCE_RAD : -CIRLCE_RAD;
}

void		set_project_type(int key,t_fdf *fdf)
{
	fdf->view->x_rad = 0.0;
	fdf->view->y_rad = 0.0;
	fdf->view->z_rad = 0.0;
	if (key == VK_I)
		fdf->view->proj = ISO;
	else if (key == VK_P)
		fdf->view->proj = PARALLEL;
}


void		manage_height(int key, t_fdf *fdf)
{
	 if (key == VK_NUM_PLUS)
	 	fdf->view->h_scale += (fdf->view->h_scale > 100) ? 0 : 1;
	 if (key == VK_NUM_MINUS)
	 	fdf->view->h_scale -= (fdf->view->h_scale < 2) ? 0 : 1;
}
