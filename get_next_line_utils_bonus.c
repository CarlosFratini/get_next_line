/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxusr <linuxusr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:29:59 by linuxusr          #+#    #+#             */
/*   Updated: 2021/10/05 22:37:37 by linuxusr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_search_nl(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(*s1));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_str_nl_cut(char *s)
{
	char	*str;
	size_t	size;
	int		i;

	i = 0;
	if (s[i] == '\0')
		return (NULL);
	size = ft_search_nl(s) + 1;
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_str_nl_rmd(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = ft_search_nl(s);
	j = 0;
	if (s[i] == '\0')
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc(sizeof(*str) * ((ft_strlen(s) - i) + 1));
	if (!str)
		return (NULL);
	i++;
	while (s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}
