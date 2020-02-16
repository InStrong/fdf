/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:54:09 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/03 23:02:19 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	destination = dst;
	source = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n)
	{
		*destination = *source;
		destination++;
		source++;
		n--;
	}
	return (dst);
}
