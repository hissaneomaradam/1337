/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 22:11:27 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/19 23:50:34 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s;
	size_t	d;

	i = 0;
	d = 0;
	s = ft_strlen(src);
	if (size == 0)
		return (s);
	while (d < size && dest[d])
		d++;
	if (d == size)
		return (size + s);
	if (size > 0)
	{
		while (src[i] && (i + d) < size - 1)
		{
			dest[d + i] = src[i];
			i++;
		}
		dest[d + i] = '\0';
	}
	return (d + s);
}
