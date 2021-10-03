/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceduard2 <ceduard2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 23:22:35 by linuxusr          #+#    #+#             */
/*   Updated: 2021/10/03 16:57:22 by ceduard2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isnl(char *s)
{
	if (s == NULL)
		return (0);
	while (*s != '\0')
	{
		if (*s++ == '\n')
			return (1);
	}
	return (0);
}

static char	*ft_get_line(char *line, int fd)
{
	char	*buffer;
	int		nbytes;

	buffer = (char *)malloc(sizeof(*buffer) + (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	nbytes = 1;
	while (!ft_isnl(line) && nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_line;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_line = ft_get_line(static_line, fd);
	if (!static_line)
		return (NULL);
	next_line = ft_str_nl_cut(static_line);
	static_line = ft_str_nl_rmd(static_line);
	return (next_line);
}
