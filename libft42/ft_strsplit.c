/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <sasajj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:21:04 by sasajj            #+#    #+#             */
/*   Updated: 2019/09/05 22:34:16 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	word_count(char const *s, char c)
{
	size_t answer;

	answer = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			answer++;
			while (*s != c && *s)
				s++;
		}
	}
	return (answer);
}

static void		ft_free_words(char **words, size_t i)
{
	while (i--)
		ft_strdel(&(words[i]));
	free(*words);
}

static char		*ft_get_word(char *word, char c)
{
	char	*answer;

	answer = word;
	while (*word != c && *word)
		word++;
	*word = '\0';
	return (ft_strdup(answer));
}

static char		**ft_get_words(char *s, char c, size_t word_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	if ((words = (char **)ft_memalloc(sizeof(char *) * (word_count + 1))))
	{
		while (i < word_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				if (!(word = ft_get_word(s, c)))
				{
					ft_free_words(words, i);
					return (NULL);
				}
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	if (!s || !(line = ft_strdup((char *)s)))
		return (NULL);
	words = ft_get_words(line, c, word_count(line, c));
	free(line);
	return (words);
}
