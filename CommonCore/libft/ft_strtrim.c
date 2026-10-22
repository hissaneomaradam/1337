/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:10:26 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/22 18:01:08 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found(const char *set, const char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	first;
	int	last;

	if (!set || !s1)
		return (NULL);
	first = 0;
	while (s1[first])
	{
		if (!found(set, s1[first]))
			break ;
		first++;
	}
	last = ft_strlen(s1) - 1;
	while (last > 0 && last > first)
	{
		if (!found(set, s1[last]))
			break ;
		last--;
	}
	return (ft_substr(s1, first, last - first + 1));
}
