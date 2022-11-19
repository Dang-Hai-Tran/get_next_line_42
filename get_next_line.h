/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:19:07 by datran            #+#    #+#             */
/*   Updated: 2022/11/20 00:03:40 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

# ifndef OPEN_MAX
# 	define OPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

int		read_buffer(int fd, char **store);
void	split_store(char **store, char **line);
int		get_next_line(int fd, char **line);

#endif
