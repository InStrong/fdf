#include "../includes/fdf.h"

int		wordcounter(char const *str, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int		get_dots_from_line(char *line, fdf **matrix_of_dots, int y)
{
	char	**dots;
	int		x;

	dots = ft_strsplit(line, ' ');
	x = 0;
	while (dots[x])
	{
		matrix_of_dots[y][x].z = ft_atoi(dots[x]);
		matrix_of_dots[y][x].x = x;
		matrix_of_dots[y][x].y = y;
		matrix_of_dots[y][x].is_last = 0;
		free(dots[x++]);
	}
	free(dots);
	free(line);
	matrix_of_dots[y][--x].is_last = 1;
	return (x);
}

fdf	**memory_allocete(char *file_name)
{
	fdf	**new;
	int		x;
	int		y;
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		exit(1);
	get_next_line(fd, &line);
	x = wordcounter(line, ' ');
	free(line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	free(line);
	new = (fdf **)malloc(sizeof(fdf *) * (++y + 1));
	while (y > 0)
		new[--y] = (fdf *)malloc(sizeof(fdf) * (x + 1));
	close(fd);
	return (new);
}

fdf	**read_file(char *file_name)
{
	fdf	**matrix_of_dots;
	int		y;
	int		fd;
	char	*line;

	matrix_of_dots = memory_allocete(file_name);
	fd = open(file_name, O_RDONLY, 0);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		get_dots_from_line(line, matrix_of_dots, y++);
	free(line);
	matrix_of_dots[y] = NULL;
	close(fd);
	return (matrix_of_dots);
}
