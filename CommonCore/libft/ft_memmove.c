/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 12:45:12 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/19 23:43:40 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dest;
	if (!dest && !src)
		return (NULL);
	if (d <= s)
		return (ft_memcpy(d, s, n));
	else
	{
		s += n;
		d += n;
		while (n--)
			*(--d) = *(--s);
	}
	return (dest);
}
#include <stdio.h>
#include <string.h>
int main ()
{
	// char *src = "Hello";
	// char dest[10];
	// printf("ccc");
	// printf("%s", (char *)memmove(dest, src, -1));hehello
	char src[6] = "hello";
	char *dest = ft_memmove(src + 2, src, 6);
	printf("%s\n", dest);
	printf("%s\n", src);


}