/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 19:18:25 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/11 23:17:26 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthex(unsigned long n)
{
	int		check;
	int		count;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		check = puthex(n / 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	check = ft_putchar(hex[n % 16]);
	if (check == -1)
		return (-1);
	count += 1;
	return (count);
}

int	ft_putptr(void *p)
{
	int	count;
	int	check;

	count = 0;
	if (!p)
		return (ft_putstr("(nil)"));
	check = ft_putstr("0x");
	if (check == -1)
		return (-1);
	count += 2;
	check = puthex((unsigned long)p);
	if (check == -1)
		return (-1);
	count += check;
	return (count);
}
