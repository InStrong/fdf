/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:27:04 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/04 21:33:02 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *str, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		if (*(src + i) != '\0')
			*(str + i) = *(src + i);
		else
		{
			while (i < len)
			{
				*(str + i) = '\0';
				i++;
			}
		}
		i++;
	}
	return (str);
}
