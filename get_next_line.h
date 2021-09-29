/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linuxusr <linuxusr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:35:44 by linuxusr          #+#    #+#             */
/*   Updated: 2021/09/29 18:47:52 by linuxusr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

size_t	ft_strlen(char *s);
int		ft_search_nl(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_str_nl_cut(char *s);
char	*ft_str_nl_rmd(char *left_str);
char	*get_next_line(int fd);

#endif
