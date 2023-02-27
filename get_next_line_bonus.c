/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-matt <lde-matt@student.42.pt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:37:11 by lde-matt          #+#    #+#             */
/*   Updated: 2023/02/27 15:15:24 by lde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	line = NULL;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
	{
		while (fd >= 0 && fd < FOPEN_MAX && buf[fd][i])
			buf[fd][i++] = 0;
		return (NULL);
	}
	while (buf[fd][0] || read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		line = strjoin_gnl(line, buf[fd]);
		if (update_buf(buf[fd]))
			break ;
	}
	return (line);
}
