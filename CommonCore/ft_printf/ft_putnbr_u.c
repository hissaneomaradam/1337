/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbru.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 03:10:19 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/11 03:10:19 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int n)
{
	int	ret;
	int	test;

	ret = 0;
	if (n >= 10)
	{
		test = ft_putnbru(n / 10);
		if (test == -1)
			return (-1);
		ret += test;
	}
	test = ft_putchar((n % 10) + '0');
	if (test == -1)
		return (-1);
	ret += test;
	return (ret);
}
