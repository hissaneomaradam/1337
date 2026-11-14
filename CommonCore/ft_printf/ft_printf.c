/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:27:06 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/14 08:18:30 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ext(va_list va)
{
	va_end(va);
	return (-1);
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
			res = handle_args(++s, va);
			s++;
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
