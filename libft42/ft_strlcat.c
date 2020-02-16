/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:48:12 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/04 21:53:42 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] && i < size)
		i++;
	while (s2[j] && (i + j + 1) < size)
	{
		s1[i + j] = s2[j];
		j++;
	}
	if (i < size)
		s1[i + j] = '\0';
	return (i + ft_strlen(s2));
}
