/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:12:03 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/10 02:17:50 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_putstr(char *s)
{
	int	check;

	if (!s)
		check = (write(1, "(null)", 6));
	else
		check = write (1, s, ft_strlen(s));
	if (check == -1)
		return (-1);
	return (check);
}
