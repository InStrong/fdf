/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:38:36 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/05 22:44:54 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_len(int n, int is_negative)
{
	size_t len;

	len = 1;
	while (n /= 10)
		len++;
	return (len + is_negative);
}

char			*ft_itoa(int n)
{
	char	*ans;
	int		len;
	int		is_negative;

	is_negative = (n < 0) ? 1 : 0;
	len = num_len(n, is_negative);
	if (!(ans = ft_strnew(len)))
		return (NULL);
	ans[len--] = '\0';
	while (len >= is_negative)
	{
		ans[len--] = is_negative ? (n % 10 * -1) + '0' : n % 10 + '0';
		n /= 10;
	}
	if (is_negative)
		ans[0] = '-';
	return (ans);
}
