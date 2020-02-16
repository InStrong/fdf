/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:07:33 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/05 00:12:01 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*answer;
	size_t	i;

	answer = NULL;
	if (s && f && (answer = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		while (s[i])
		{
			answer[i] = f(s[i]);
			i++;
		}
		answer[i] = '\0';
	}
	return (answer);
}
