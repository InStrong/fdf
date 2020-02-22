#include "../includes/fdf.h"
#include <math.h>
#include <stdio.h>

#define MAX(a,b) (a > b ? a : b)
#define ABS(a) (a < 0 ? -a : a)

// void	isometric(float *x, float *y, int z)
// {
// 	*x = (*x - *y) * cos(0.8);
// 	*y = (*x + *y) * sin(0.8) - z;
// }

void	draw_bresenham(fdf a, fdf b, fdf *data)
{
	float x_step;
	float y_step;
	float max;
	
	// data->z = data->z_matrix[(int)data->y][(int)data->x];
	// data->z1 = data->z_matrix[(int)y1][(int)x1];

	// // zoom
	// data->x *= data->zoom;
	// data->x1 *= data->zoom;
	// data->y *= data->zoom;
	// data->y1 *= data->zoom;
	// //color 
	// data->color = (data->z || data->z1) ? 0xe80c0c : 0xffffff;
	//isometric
	// isometric(&x, &y, z);
	// isometric(&x1, &y1, z1);
	//shift
	set_param(&a, &b, data);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = MAX(ABS(x_step),ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, 0xBBFAFF);
		a.x += x_step;
		a.y += y_step;
		if (a.y < 0 || a.x < 0)
			break ;
	}	
}

void	draw(fdf **data)
{
	int		y;
	int		x;

	y = 0;
	while (data[y])
	{
		x = 0;
		while (1)
		{
			if (data[y + 1])
				draw_bresenham(data[y][x], data[y + 1][x], &data[0][0]);
			if (!data[y][x].is_last)
				draw_bresenham(data[y][x], data[y][x + 1], &data[0][0]);
			if (data[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}