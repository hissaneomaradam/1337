/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:38:11 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/29 11:38:11 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_mem(char **p1, size_t n)
{
	while (n--)
		free(p1[n]);
	free(p1);
}

static int	fill(char **p1, const char *p, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (p[i])
	{
		if (p[i] == c)
			i++;
		else
		{
			len = word_len(p + i, c);
			p1[j] = ft_substr(p, i, len);
			if (!p1[j])
			{
				free_mem(p1, j);
				return (0);
			}
			j++;
			i += len;
		}
	}
	p1[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**p;

	if (!s)
		return (NULL);
	p = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	if (!fill(p, s, c))
		return (NULL);
	return (p);
}
