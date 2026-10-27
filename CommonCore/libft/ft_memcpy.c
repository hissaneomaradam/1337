/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 01:37:20 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/24 21:52:04 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
	{
		*d = *s;
		s++;
		d++;
	}
	return (dest);
}
#include <stdio.h>
#include <string.h>
int main ()
{
	char *src = "Hello";
	char dest[10];
	printf("ccc");
	printf("%s", (char *)ft_memcpy(NULL, NULL, 5));
	// printf("%d" (char *)ft_memcpy(dest, src, 5));
}