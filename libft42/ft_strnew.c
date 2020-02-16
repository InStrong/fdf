/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 23:45:45 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/04 23:49:30 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *tmp;

	if (size + 1 < size)
		return (NULL);
	tmp = (char*)ft_memalloc(sizeof(char) * (size + 1));
	return (tmp);
}
