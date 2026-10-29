/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 02:00:10 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/29 02:31:00 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	return (NULL);
}
#include <stdio.h>
#include <string.h>
int	main()
{
	char *p = "hello world";
	printf("%s\n", ft_memchr(NULL, 'w', 5));
}
