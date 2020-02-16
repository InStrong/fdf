/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:10:49 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/05 00:11:35 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*answer;
	size_t	i;

	answer = NULL;
	if (s && f && (answer = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (s[i])
		{
			answer[i] = f(i, s[i]);
			i++;
		}
		answer[i] = '\0';
	}
	return (answer);
}
