#include "fdf.h"
#include <stdio.h>
#include "stdlib.h"
#include "../libft/libft.h"

int	deal_key(int key, fdf *data)
{
	printf("%d\n", key);
	if (key == 126)
		data->shift_y -= 10;
	else if (key == 125)
		data->shift_y += 10;
	else if (key == 124)
		data->shift_x += 10;
	else if (key == 123)
		data->shift_x -= 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	fdf *data;

	if (argc != 2)
	{
		ft_putstr("usage: fdf map.txt\n");
		return (0);
	}
	data = (fdf*)malloc(sizeof(fdf));
	data->shift_x = 0;
	data->shift_y = 0;
	read_file(data, argv[1]);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	//draw_bresenham(10, 10, 600, 300, data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	
}