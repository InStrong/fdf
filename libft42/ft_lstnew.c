/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:34:29 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/05 23:37:03 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ans;

	if (!(ans = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!content || content_size == 0)
	{
		ans->content = NULL;
		ans->content_size = 0;
	}
	else
	{
		if (!(ans->content = ft_memalloc(content_size)))
		{
			free(ans);
			return (NULL);
		}
		ft_memcpy(ans->content, content, content_size);
		ans->content_size = content_size;
	}
	ans->next = NULL;
	return (ans);
}
