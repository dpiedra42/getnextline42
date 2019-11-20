/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:39:19 by dpiedra           #+#    #+#             */
/*   Updated: 2019/11/20 17:31:06 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE (32)
#endif

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*str;
	int			red;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	if ((red = read(fd, buf, BUFFER_SIZE) == -1))
		return (-1);
	if (red == 0)
		return (0);
	while ((check_new(str) != 1) && red > 0)
	{
		if ((red = read(fd, buf, BUFFER_SIZE) == -1))
			return (-1);
		buf[red] = '\0';
		str = ft_strjoin(str, buf);
	}
	*line = get_line(str);
	return (1);
}
