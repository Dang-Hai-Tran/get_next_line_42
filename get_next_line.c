/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:18:13 by datran            #+#    #+#             */
/*   Updated: 2022/11/19 23:21:55 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(int fd, char **store)
{
	int		bytes;
	char	*tmp;
	char	*buf;

	if (BUFFER_SIZE > 0)
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	else
		return (0);
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes < 0 || buf == NULL)
		return (-1);
	buf[bytes] = 0;
	tmp = ft_strjoin(*store, buf);
	free(*store);
	*store = tmp;
	free(buf);
	buf = NULL;
	if (bytes > 1)
		return (1);
	return (bytes);
}

void	split_store(char **store, char **line)
{
	size_t	len;
	char	*tmp;
	
	len = ft_strchr(*store, '\n') - *store;
	*line = ft_substr(*store, 0, len);
	tmp = ft_substr(*store, len + 1, ft_strlen(*store) - len);
	free(*store);
	*store = tmp;
}

int	get_next_line(int fd, char **line)
{
	int			bytes;
	static char	*store[OPEN_MAX];
	
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (store[fd] == NULL)
		store[fd] = ft_strdup("");
	bytes = 1;
	while (bytes > 0 && ft_strchr(store[fd], '\n') == NULL)
		bytes = read_buffer(fd, &store[fd]);
	if (ft_strchr(store[fd], '\n'))
		split_store(&store[fd], line);
	if (bytes == 0 && ft_strchr(store[fd], '\n') == NULL)
	{
		*line = ft_strdup(store[fd]);
		free(store[fd]);
		store[fd] = NULL;
	}
	return (bytes);
}
