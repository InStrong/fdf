/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:18:39 by cspider           #+#    #+#             */
/*   Updated: 2020/02/22 21:46:02 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define FD_SIZE 4096

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_arr
{
	int				fd;
	char			*rest;
	struct s_arr	*next;
}				t_arr;
int		get_next_line(const int fd, char **line);

#endif
