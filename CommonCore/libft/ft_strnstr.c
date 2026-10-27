/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 22:57:40 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/19 23:49:44 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while ((i + j < len) && big[i + j] == little[j] && little[j])
		{
			j++;
			if (!little[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
#include <bsd/string.h>
#include <stdio.h>
int	main()
{
	char * res;
	res = ft_strnstr("he€o","€" , 4);
	printf("%s\n", res);
}
