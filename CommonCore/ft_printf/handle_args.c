/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 04:08:52 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/14 04:08:52 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_args(const char *s, va_list va)
{
	if (!s)
		return (-1);
	if (*s == 'c')
		return (ft_putchar(va_arg(va, int)));
	if (*s == 's')
		return (ft_putstr(va_arg(va, char *)));
	if (*s == 'p')
		return (ft_putptr(va_arg(va, void *)));
	if (*s == 'i' || *s == 'd')
		return (ft_putnbr(va_arg(va, int)));
	if (*s == 'u')
		return (ft_putnbru(va_arg(va, unsigned int)));
	if (*s == 'x')
		return (ft_putlhex(va_arg(va, unsigned int)));
	if (*s == 'X')
		return (ft_putuhex(va_arg(va, unsigned int)));
	if (*s == '%')
		return (ft_putchar('%'));
	return (-1);
}
