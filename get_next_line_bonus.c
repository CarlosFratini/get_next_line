/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxusr <linuxusr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 23:22:35 by linuxusr          #+#    #+#             */
/*   Updated: 2021/09/28 21:42:11 by linuxusr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *line, int fd)
{
	char	*buffer;
	int		nbytes;

	buffer = (char *)malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	nbytes = 1;
	while (ft_search_nl(line) == 0 && nbytes != 0)
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
	static char	*static_line[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	static_line[fd] = ft_get_line(static_line[fd], fd);
	if (!static_line[fd])
		return (NULL);
	next_line = ft_str_nl_cut(static_line[fd]);
	static_line[fd] = ft_str_nl_rmd(static_line[fd]);
	return (next_line);
}
