/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   natoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 23:59:16 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/27 01:39:05 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	natoi(const char *n)
{
	int	sign;
	long res;

	sign = 1;
	res = 0;
	while (*n == ' ' || (*n >= 9 && *n <= 13 ))
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign = -1;
		n++;
	}
	while (*n >= '0' && *n <= '9')
	{
		if (res > (9223372036854775807 - (*n - '0')) / 10)
		{
			if (sign < 0)
				return (0);
			return (-1);
		}
		res = res * 10 + (*n++ - '0');
	}
	return (sign * res);
}
#include <stdlib.h>
#include <stdio.h>
int	main()
{
	printf("%d\n", natoi("------1"));
	printf("%d\n", atoi("------1"));
}
