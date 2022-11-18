/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:17:12 by datran            #+#    #+#             */
/*   Updated: 2022/11/17 23:38:11 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = ft_strlen(str);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] != 0)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != 0)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			slen;
	
	slen = ft_strlen(s);
	sub = (char *)malloc(sizeof(char) * (slen - start + 1));
	if (!sub || !s)
		return (NULL);
	i = 0;
	while (start < slen && start + i < slen && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

int main()
{
	char *s = ft_strdup("hello world");
	unsigned int start = 7;
	size_t	len = 10;
	printf("%s\n", ft_substr(s, start, len));
	printf("%lu\n", ft_strlen(ft_substr(s, start, len)));
	return (0);
}
