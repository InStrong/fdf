/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:52:16 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/04 23:35:21 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)));
}

int			ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	answer;
	unsigned long	border;

	border = FT_LONG_MAX / 10;
	i = 0;
	answer = 0;
	sign = 1;
	while (is_whitespace(str[i]))
		i++;
	sign = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if ((answer > border || (answer == border && (str[i] - '0') > 7))
			&& sign == 1)
			return (-1);
		if ((answer > border || (answer == border && (str[i] - '0') > 8))
			&& sign == -1)
			return (0);
		answer = answer * 10 + str[i++] - '0';
	}
	return ((int)(answer * sign));
}
