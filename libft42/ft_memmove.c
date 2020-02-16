/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:18:32 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/05 23:26:29 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*destination;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	if (destination == NULL && source == NULL)
		return (NULL);
	if (destination < source)
		while (len--)
			*destination++ = *source++;
	else
	{
		destination += len;
		source += len;
		while (len--)
			*--destination = *--source;
	}
	return (dst);
}
