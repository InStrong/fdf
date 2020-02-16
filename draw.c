#include "fdf.h"

#define MAX(a,b) (a > b ? a : b)
#define ABS(a) (a < 0 ? -a : a)

void	draw_bresenham(float x, float y, float x1, float y1, fdf *data)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	// zoom
	x *= data->zoom;
	x1 *= data->zoom;
	y *= data->zoom;
	y1 *= data->zoom;
	//color 
	data->color = (z) ? 0xe80c0c : 0xffffff;
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(ABS(x_step),ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				draw_bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				draw_bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}