/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 19:38:33 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/20 20:17:56 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (res > (9223372036854775807 - (*nptr - '0')) / 10)
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		res = res * 10 + (*nptr++ - '0');
	}
	return (sign * res);
}
#include <stdio.h>
int main ()
{
	printf("%d\n", ft_atoi("54444444444444444444"));
	printf("%d\n", atoi("54444444444444444444"));
}