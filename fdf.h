#ifndef FDF_H
# define FDF_H

#include "libft42/libft.h"
#include "minilibx_macos/mlx.h"
#include <fcntl.h>

typedef		struct
{
	int		width;
	int		height;
	int		**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}			fdf;

void	read_file(fdf *data, char *file_name);

#endif