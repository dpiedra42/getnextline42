/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:01:44 by dpiedra           #+#    #+#             */
/*   Updated: 2019/11/22 15:48:58 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*ptr;
	int		fd;
	int		result;

	fd = open("tests.txt", O_RDONLY);
	result = 1;
	while (result)
	{
		result = get_next_line(fd, &ptr);
		printf("String is: %s\n", ptr);
		free(ptr);
	}
	return (0);
}
