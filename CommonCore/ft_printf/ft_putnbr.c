/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:33:00 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/17 23:15:39 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(int n)
{
	int	check;

	check = ft_putchar(n + '0');
	if (check == -1)
		return (-1);
	return (check);
}

int	ft_putnbr(int n)
{
	int	count;
	int	check;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		check = ft_putchar('-');
		if (check == -1)
			return (-1);
		count += check;
		n = -n;
	}
	if (n >= 10)
	{
		check = ft_putnbr(n / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = helper(n % 10);
	if (check == -1)
		return (-1);
	return (count + check);
}
