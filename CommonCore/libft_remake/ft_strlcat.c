/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 23:22:49 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/29 01:00:23 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;

	s = ft_strlen(src);
	d = 0;
	while (d < size && dest[d])
		d++;
	if (d == size)
		return (d + s);
	if (size > 0)
	{
		i = 0;
		while (src[i] && (i + d) < (size - 1))
		{
			dest[d + i] = src[i];
			i++;
		}
		dest[d + i] = '\0';
	}
	return (d + s);
}
