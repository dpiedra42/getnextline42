/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:39:19 by dpiedra           #+#    #+#             */
/*   Updated: 2019/11/22 11:50:28 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE (1)
#endif

char	*del_line(char *s)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		i = i + 1;
	if (!(newstr = malloc(sizeof(char) * (ft_strlen(s)) - i + 1)))
		return (NULL);
	j = 0;
	while (s[i] != '\0')
	{
		newstr[j] = s[i];
		j++;
		i++;
	}
	free(s);
	newstr[j] = '\0';
	return (newstr);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*str;
	int			red;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	red = 1;
	while ((red != 0) && (check_new(str) != 1))
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red == -1)
			return (-1);
		buf[red] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	*line = get_line(str);
	str = del_line(str);
	if (red == 0)
		return (0);
	return (1);
}
