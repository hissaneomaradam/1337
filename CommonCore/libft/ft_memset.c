/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:35:17 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/28 04:26:46 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p = (unsigned char)c;
		p++;
	}
	return (s);
}
#include <stdio.h>
int	main()
{
	int	p;
	// int	i;
	// while (i < 4)
	// {
	// 	ft_memset((char *)&p + i, 255, 1);
	// 	i++;
	// }
	ft_memset(&p, 95, 1);
	ft_memset((char *)&p + 1, 164, 1);
	ft_memset((char *)&p + 2, 255, 1);
	ft_memset((char *)&p + 3, 255, 1);
	printf("%d\n", p);
}
