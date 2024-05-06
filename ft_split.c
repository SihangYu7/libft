/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:59:39 by siyu              #+#    #+#             */
/*   Updated: 2024/05/02 17:01:07 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_if_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	if (!s)
		return (count);
	while (*s)
	{
		if (*s == c && in_word)
			in_word = 0;
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static void	skip_delimiter(char const **s, char c)
{
	while (**s == c)
		(*s)++;
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static const char	*copy_word(char **arr, size_t index, char const *s, char c)
{
	size_t	len;

	len = word_len(s, c);
	arr[index] = ft_substr(s, 0, len);
	if (!arr[index])
		return (NULL);
	return (s + len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	num_words;

	num_words = count_if_words(s, c);
	str = (char **)malloc(sizeof(*str) * (num_words + 1));
	if (!str || !s)
		return (NULL);
	i = 0;
	while (num_words--)
	{
		skip_delimiter(&s, c);
		s = copy_word(str, i, s, c);
		if (!s)
		{
			while (i--)
				free(str[i]);
			free(str);
			return (NULL);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}
