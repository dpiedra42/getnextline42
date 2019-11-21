/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:01:44 by dpiedra           #+#    #+#             */
/*   Updated: 2019/11/21 17:26:22 by dpiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char *ptr;
	int fd;
	int fd2 = 0;
	int result;

	fd = open("tests.txt", O_RDONLY);
	while ((result = get_next_line(fd, &ptr)) > 0)
	{
		printf("String is: %s\n", ptr);
		printf("This is my return: %d\n", result);
		free(ptr);
	}
	
	printf("String is: %s\n", ptr);
	printf("This is my return: %d\n", result);
	free(ptr);
}