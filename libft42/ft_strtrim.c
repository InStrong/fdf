/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:10:15 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/05 22:18:52 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (ft_iswhitespace(s[i]))
		i++;
	while (ft_iswhitespace(s[len - 1]))
		len--;
	if (len < i)
		len = i;
	return (ft_strsub(s, i, len - i));
}
