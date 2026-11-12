/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 00:11:49 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/12 00:28:37 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlhex(unsigned int n)
{
	char	*hex;
	int		check;
	int		res;

	hex = "0123456789abcdef";
	check = 0;
	res = 0;
	if (n >= 16)
	{
		check = ft_putlhex(n / 16);
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
