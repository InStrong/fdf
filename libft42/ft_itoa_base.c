/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:32:50 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/06 21:48:00 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int num, int base)
{
	long long		tmp;
	int				len;
	int				sign;
	char			*out;

	if (base < 2)
		return (NULL);
	tmp = (long long)((num < 0) ? -(num + 1) : num - 1) + 1;
	sign = (num < 0 && base == 10) ? 1 : 0;
	len = sign;
	while (tmp /= base)
		len++;
	if (!(out = ft_strnew(len + 1)))
		return (NULL);
	if (sign)
		out[0] = '-';
	tmp = (long long)((num < 0) ? -(num + 1) : num - 1) + 1;
	while (len - sign + 1)
	{
		out[len] = ((tmp % base) >= 10) ? (tmp % base) + 'A' - 10
										: (tmp % base) + '0';
		tmp /= base;
		len--;
	}
	return (out);
}
