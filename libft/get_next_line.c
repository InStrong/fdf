/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:04:11 by sasajj            #+#    #+#             */
/*   Updated: 2019/11/21 21:37:08 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	append_line(char **new_str, char **line)
{
	char	*temp;
	int		len;

	len = 0;
	while ((*new_str)[len] != '\n' && (*new_str)[len] != '\0')
		len++;
	if ((*new_str)[len] == '\n')
	{
		*line = ft_strsub(*new_str, 0, len);
		temp = ft_strdup(&((*new_str)[len + 1]));
		free(*new_str);
		*new_str = temp;
		if ((*new_str)[0] == '\0')
			ft_strdel(new_str);
	}
	else
	{
		*line = ft_strdup(*new_str);
		ft_strdel(new_str);
	}
	return (1);
}

static int	to_return(char **str, char **line, int answer, int fd)
{
	if (answer < 0)
		return (-1);
	else if (answer == 0 && str[fd] == NULL)
		return (0);
	else
		return (append_line(&str[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int				answer;
	static char		*str[FD_SIZE];
	char			buff[BUFF_SIZE + 1];
	char			*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((answer = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[answer] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (to_return(str, line, answer, fd));
}
