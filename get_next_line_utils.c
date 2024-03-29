/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:39:15 by dpiedra           #+#    #+#             */
/*   Updated: 2019/11/26 12:28:19 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_new(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sjoin;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(sjoin = malloc(sizeof(char) * ((len1 + len2) + 1))))
		return (NULL);
	ft_memmove(sjoin, s1, len1);
	ft_memmove(sjoin + len1, s2, len2);
	sjoin[len1 + len2] = '\0';
	free((void *)s1);
	return (sjoin);
}

char	*get_line(char *s1)
{
	int		i;
	char	*lineread;

	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	if (!(lineread = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		lineread[i] = s1[i];
		i++;
	}
	lineread[i] = '\0';
	return (lineread);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dest;
	unsigned char *source;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dest < source)
	{
		while (len--)
		{
			*dest = *source;
			dest++;
			source++;
		}
	}
	else if (dest > source)
		while (len--)
			*(dest + len) = *(source + len);
	return (dst);
}
