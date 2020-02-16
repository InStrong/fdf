/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:21:09 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/04 22:41:55 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		needle_len;
	size_t		i;
	size_t		j;
	char		*haystack_noconst;

	haystack_noconst = (char *)haystack;
	if (!(needle_len = ft_strlen(needle)))
		return (haystack_noconst);
	if (ft_strlen(haystack_noconst) < needle_len || len < needle_len)
		return (NULL);
	i = 0;
	while (haystack_noconst[i] && i <= len - needle_len)
	{
		j = 0;
		while (needle[j] && needle[j] == haystack_noconst[i + j])
		{
			j++;
			if (j == needle_len)
				return (&haystack_noconst[i]);
		}
		i++;
	}
	return (NULL);
}
