/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 00:31:36 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/12 00:31:36 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuhex(unsigned int n)
{
	char	*hex;
	int		check;
	int		res;

	hex = "0123456789ABCDEF";
	check = 0;
	res = 0;
	if (n >= 16)
	{
		check = ft_putuhex(n / 16);
		if (check == -1)
			return (-1);
		res += check;
	}
	check = ft_putchar(hex[n % 16]);
	if (check == -1)
		return (-1);
	res += 1;
	return (res);
}
