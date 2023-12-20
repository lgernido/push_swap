/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 08:17:11 by lgernido          #+#    #+#             */
/*   Updated: 2023/12/20 11:50:11 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			size;
	int			i;

	size = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while ((s[cursor + size] != c) && s[cursor + size])
		size++;
	next_word = malloc((size_t)size * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

void	free_split(char **split_array)
{
	int	i;

	i = 0;
	while (split_array[i] != NULL)
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}

char	**ft_split(char *s, char c)
{
	int		words_count;
	char	**res;
	int		i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	res = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!res)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			res[i] = malloc(sizeof(char));
			if (!res[i])
				return (NULL);
			res[i++][0] = '\0';
			continue ;
		}
		res[i++] = get_next_word(s, c);
	}
	res[i] = NULL;
	return (res);
}
