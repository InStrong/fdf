/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:23:23 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/03 22:45:14 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = b;
	while (len != 0)
	{
		*p = c;
		p++;
		len--;
	}
	return (b);
}