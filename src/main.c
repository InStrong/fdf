#include "../includes/fdf.h"
#include <stdio.h>
#include "stdlib.h"
#include "../libft/libft.h"

int	deal_key(int key, fdf **data)
{
	
	printf("%d\n", key);
	if (key == 126)
		data[0][0].shift_y -= 10;
	else if (key == 125)
		data[0][0].shift_y += 10;
	else if (key == 124)
		data[0][0].shift_x += 10;
	else if (key == 123)
		data[0][0].shift_x -= 10;
	else if (key == 24 || key == 69)
		data[0][0].zoom += 1;
	else if (key == 27 || key == 78)
		data[0][0].zoom -= 1;
	else if (key == 49 || key == 87 || key == 23)
		data[0][0].is_isometric = (data[0][0].is_isometric) ? 0 : 1;
	if (key == '5')
	{
		mlx_destroy_window(data[0][0].mlx_ptr, data[0][0].win_ptr);
		free(data);
		exit(0);
	}
	
	mlx_clear_window(data[0][0].mlx_ptr, data[0][0].win_ptr);
	print_menu(*data);
	draw(data);
	return (0);
}

void	set_default(fdf *param)
{
	param->zoom = 20;
	param->z_zoom = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	//param->win_x = 2000;
	//param->win_y = 1000;
	//param->shift_x = param->win_x / 3;
	//param->shift_y = param->win_y / 3;
	param->shift_x = 400;
	param->shift_y = 400;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, 1000, 1000, "FDF");
}


int	main(int argc, char **argv)
{
	fdf **data;

	if (argc != 2)
	{
		ft_putstr("usage: fdf map.txt\n");
		return (0);
	}
	//data = (fdf*)malloc(sizeof(fdf));
	data = read_file(*++argv);
	// data->shift_x = 500;
	// data->shift_y = 500;
	
	// data->mlx_ptr = mlx_init();
	// data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	// data->zoom = 8;
	//draw_bresenham(10, 10, 600, 300, data);
	set_default(&data[0][0]);
	draw(data);
	mlx_key_hook(data[0][0].win_ptr, deal_key, data);
	mlx_loop(data[0][0].mlx_ptr);
	
}