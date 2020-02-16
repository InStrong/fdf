/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:08:55 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/04 22:20:16 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t needle_counter;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		needle_counter = 0;
		while (*(haystack + needle_counter) == needle[needle_counter]
			&& *(haystack + needle_counter) != '\0')
		{
			if (needle[needle_counter + 1] == '\0')
				return ((char *)haystack);
			needle_counter++;
		}
		haystack++;
	}
	return (0);
}
