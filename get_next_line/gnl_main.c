/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:09:43 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/07/28 05:51:01 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd_1;
	int		fd_2;
	int		i;
	char	*line[4096];

	i = 1;
	fd_1 = open("empty.txt", O_RDONLY);
	fd_2 = open("newline.txt", O_RDONLY);
	while (1)
	{
		line[fd_1] = get_next_line(fd_1);
		printf("Line %d for fd %d: %s\n", i, fd_1, line[fd_1]);
		free(line[fd_1]);
		if (line[fd_1] == 0)
			break ;
		i++;
	}
	while (1)
	{
		line[fd_2] = get_next_line(fd_2);
		printf("Line %d for fd %d: %s\n", i, fd_2, line[fd_2]);
		free(line[fd_2]);
		if (line[fd_2] == 0)
			break ;
		i++;
	}
}

