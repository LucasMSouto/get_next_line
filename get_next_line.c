/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-matt <lde-matt@student.42.pt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:37:11 by lde-matt          #+#    #+#             */
/*   Updated: 2023/02/22 13:12:27 by lde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		while (buf[i])
			buf[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buf[0] || read(fd, buf, BUFFER_SIZE) > 0)
	{
		line = strjoin_gnl(line, buf);
		if (update_buf(buf))
			break ;
	}
	return (line);
}
