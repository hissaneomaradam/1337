/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:27:06 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/18 16:58:59 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ext(va_list va)
{
	va_end(va);
	return (-1);
}

static int	handle_format(const char **s, va_list va)
{
	int	res;

	res = 0;
	(*s)++;
	if (!**s)
		return (ft_putchar('%'));
	res = handle_args(*s, va);
	(*s)++;
	return (res);
}

static int	iter(const char *s, va_list va)
{
	int	res;
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			res = handle_format(&s, va);
		}
		else
		{
			res = ft_write(s);
			if (res != -1)
				s += res;
		}
		if (res == -1)
			return (ext(va));
		count += res;
	}
	va_end(va);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	va;

	if (!s)
		return (-1);
	va_start(va, s);
	return (iter(s, va));
}
