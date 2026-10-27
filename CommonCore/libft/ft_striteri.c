/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 19:07:58 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/24 19:20:25 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
#include <stdio.h>
void set(unsigned int s, char * c)
{
	(void)s;
	(void)c;
	printf("%c\n", '*');
}
int	main()
{
	char *s = "hello";
	ft_striteri(s, set);
}
