/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:50:36 by mtocu             #+#    #+#             */
/*   Updated: 2024/05/14 12:14:30 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!src)
		return (0);
	i = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize == 0)
		return (i);
	j = 0;
	while (src[j] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize > 0)
		dst[j] = '\0';
	return (i);
}

static size_t	word_count(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

/*  duplicates a word with the given length from the start pointer */
static char	*word_dup(const char *start, size_t len)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

/* Allocates (withmalloc(3)) and returns an array of strings obtained by
 * splitting ’s’ using the character ’c’ as a delimiter.
 * The array must end with a NULL pointer */
char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	len;
	char	*start;

	split = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!s || !split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		start = (char *)s;
		len = 0;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (len)
			split[i++] = word_dup(start, len);
	}
	split[i] = NULL;
	return (split);
}
