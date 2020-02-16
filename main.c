#include "fdf.h"
#include <stdio.h>
#include "stdlib.h"
#include "libft42/libft.h"

int	deal_key(int key, fdf *data)
{
	printf("%d\n", key);
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 123)
		data->shift_x -= 10;
	else
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	fdf *data;

	data = (fdf*)malloc(sizeof(fdf));
	read_file(data, argv[1]);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	//draw_bresenham(10, 10, 600, 300, data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	
}