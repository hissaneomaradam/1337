/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 09:13:37 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/29 09:13:37 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	size_t	len;
	char	*p;
	
	ls1 = 0;
	ls2 = 0;
	if (s1)
		ls1 = ft_strlen(s1);
	if (s2)
		ls2 = ft_strlen(s2);
	p  = malloc(ls1 + ls2 + 1);
	if (!p)
		return (NULL);
	if (s1)
		ft_memcpy(p, s1, ls1);
	if (s2)
		ft_memcpy(p + ls1, s2, ls2);
	p[ls1 + ls2] = '\0';
	return (p);
}
