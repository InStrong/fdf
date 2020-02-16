/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:04:29 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/04 00:18:08 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*tmp;
	char	*result;
	size_t	mem_length;

	i = 0;
	mem_length = sizeof(char) * ft_strlen(src) + 1;
	tmp = (char*)malloc(mem_length);
	if (tmp == NULL)
		return (NULL);
	if (!(result = (char *)ft_memcpy(tmp, src, mem_length)))
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}
