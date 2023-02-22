/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-matt <lde-matt@student.42.pt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:37:49 by lde-matt          #+#    #+#             */
/*   Updated: 2023/02/22 13:40:54 by lde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

# ifndef FOPEN_MAX
#  define FOPEN_MAX 8
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		find_break(char *str);
int		update_buf(char *buf);
char	*strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
