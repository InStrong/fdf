/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:11:27 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/05 22:12:20 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}
