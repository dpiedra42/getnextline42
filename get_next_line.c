/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:39:19 by dpiedra           #+#    #+#             */
/*   Updated: 2019/11/20 15:39:02 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE (32)
#endif 

int	check_new(char *str)
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

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*str;
	int			red;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((check_new(str) != 1) && ((red = read(fd, buf, BUFFER_SIZE) < 0 )))
	{
		if (red < 0)
			return (-1);
	}
	return (1);
}