#ifndef FDF_H
# define FDF_H

#include "../libft/libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <math.h>

typedef		struct
{
	float	x;
	float	y;
	float	z;
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		z_zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		is_last;
	double	angle;
	int		is_isometric;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

fdf		**read_file(char *file_name);
//void	draw_bresenham(float x, float y, float x1, float y1, fdf *data);
void	draw(fdf **data);
int		get_dots_from_line(char *line, fdf **matrix_of_dots, int y);
void	print_menu(fdf *data);
void	isometric(fdf *dot, double angle);
void	set_param(fdf *a, fdf *b, fdf *param);

#endif