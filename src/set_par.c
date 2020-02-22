#include "../includes/fdf.h"

void	zoom(fdf *a, fdf *b, fdf *param)
{
	a->x *= param->zoom;
	a->y *= param->zoom;
	b->x *= param->zoom;
	b->y *= param->zoom;
	a->z *= param->z_zoom;
	b->z *= param->z_zoom;
}

void	set_param(fdf *a, fdf *b, fdf *param)
{
	zoom(a, b, param);
	if (param->is_isometric)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}
