/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:10:10 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/10 18:30:37 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbru(unsigned int n);
int	ft_putuhex(unsigned int n);
int	ft_putlhex(unsigned int n);
int	ft_putptr(void *p);
int	handle_args(const char *s, va_list va);
int	ft_write(const char *s);
int	ft_printf(const char *s, ...);

#endif
