/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohissane <ohissane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 09:38:27 by ohissane          #+#    #+#             */
/*   Updated: 2026/11/26 22:29:19 by ohissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*cleanreturn(char *p)
{
	free(p);
	return (NULL);
}

static char	*ft_readn(int fd, char *stash)
{
	char	*b;
	char	*old_s;
	ssize_t	bytes_read;

	b = malloc((size_t)BUFFER_SIZE + 1);
	if (!b)
		return (cleanreturn(stash));
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, b, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			b[bytes_read] = '\0';
			old_s = stash;
			stash = ft_strjoin(old_s, b);
			free(old_s);
			if (!stash)
				return (cleanreturn(b));
		}
	}
	free(b);
	if (bytes_read == -1)
		return (cleanreturn(stash));
	return (stash);
}

static char	*get_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

static char	*whats_left(char *stash)
{
	char	*left;
	size_t	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (cleanreturn(stash));
	left = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
	free(stash);
	if (left && !*left)
		return (cleanreturn(left));
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_readn(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	if (!line)
		return (NULL);
	stash = whats_left(stash);
	return (line);
}
