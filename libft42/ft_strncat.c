/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:40:58 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/04 21:46:16 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t s1_len;
	size_t s2_len;
	size_t i;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	n = (s2_len < n) ? s2_len : n;
	while (n--)
	{
		*(s1 + s1_len + i) = *(s2 + i);
		i++;
	}
	*(s1 + s1_len + i) = '\0';
	return (s1);
}
