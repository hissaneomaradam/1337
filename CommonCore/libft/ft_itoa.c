/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 05:50:18 by ohissane          #+#    #+#             */
/*   Updated: 2026/10/30 06:06:44 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;
	long	num;

	num = n;
	len = numlen(num);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = 0;
	if (num < 0)
	{
		p[0] = '-';
		num *= -1;
	}
	if (num == 0)
	{
		p[0] = '0';
	}
	while (num > 0)
	{
		p[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (p);
}
