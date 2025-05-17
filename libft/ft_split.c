/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seizquie <seizquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:13:42 by seizquie          #+#    #+#             */
/*   Updated: 2024/10/13 21:02:27 by seizquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			words++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (words);
}

static char	**ft_fill_result(char **result, char const *s, char c)
{
	int				i;
	char const		*initial_word;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		initial_word = s;
		s = ft_strchr(s, c);
		if (s == NULL)
			s = ft_strchr(initial_word, '\0');
		result[i] = ft_substr(initial_word, 0, s - initial_word);
		if (result[i] == NULL)
		{
			while (--i >= 0)
				free(result[i]);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc((ft_count_words(s, c) + 1) * sizeof (char *));
	if (result == NULL)
		return (NULL);
	if (ft_fill_result(result, s, c) == NULL)
	{
		free(result);
		return (NULL);
	}
	return (result);
}
