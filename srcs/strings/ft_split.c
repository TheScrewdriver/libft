/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbroque <rbroque@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:29:49 by rbroque           #+#    #+#             */
/*   Updated: 2022/09/15 22:44:00 by rbroque          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	bool	is_word;

	count = 0;
	is_word = false;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (is_word == true)
			{
				++count;
				is_word = false;
			}
		}
		else
			is_word = true;
		++s;
	}
	return (count + (is_word == true));
}

static void	skipchr(const char **s, char c)
{
	while (**s == c)
		++*s;
}

static size_t	get_wordlen(const char *s, char c)
{
	size_t	wordlen;

	wordlen = 0;
	while (s[wordlen] != '\0' && s[wordlen] != c)
		++wordlen;
	return (wordlen);
}

static char	*get_word(const char **s, char c)
{
	const size_t	wordlen = get_wordlen(*s, c);
	char			*word;

	skipchr(s, c);
	word = ft_strndup(*s, wordlen);
	word[wordlen] = '\0';
	*s += wordlen;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	const size_t	nbof_words = count_words(s, c);
	size_t			i;
	char			**split;

	split = (char **)malloc((nbof_words + 1) * sizeof(char *));
	if (split != NULL)
	{
		i = 0;
		while (i < nbof_words)
		{
			split[i] = get_word(&s, c);
			++i;
		}
		split[nbof_words] = NULL;
	}
	return (split);
}
