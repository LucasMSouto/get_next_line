/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-matt <lde-matt@student.42.pt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:37:11 by lde-matt          #+#    #+#             */
/*   Updated: 2023/02/22 14:26:22 by lde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (buf[fd][i])
			buf[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buf[fd][0] || read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		line = strjoin_gnl(line, buf[fd]);
		if (update_buf(buf[fd]))
			break ;
	}
	return (line);
}

#include <stdio.h>

int	main()
{
	int	fd1 = open("lines_around_10.txt", O_RDONLY);
	int	fd2 = open("~/francinette/tests/get_next_line/fsoares/giant_line_nl.txt", O_RDONLY);
	char	*ln;
	get_next_line(fd2);
	printf("fd1\tline1:\t%s", ln);
	free(ln);
	get_next_line(fd2);
	printf("fd2\tline1:\t%s", ln);
	free(ln);
}
