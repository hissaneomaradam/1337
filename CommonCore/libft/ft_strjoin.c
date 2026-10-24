/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 20:16:39 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/24 21:53:28 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	si1;
	size_t	si2;
	char	*p;

	si1 = 0;
	si2 = 0;
	if (s1)
		si1 = ft_strlen(s1);
	if (s2)
		si2 = ft_strlen(s2);
	p = malloc(si1 + si2 + 1);
	if (!p)
		return (NULL);
	if (s1)
		ft_memcpy(p, s1, si1);
	if (s2)
		ft_memcpy(p + si1, s2, si2);
	p[si1 + si2] = '\0';
	return (p);
}
