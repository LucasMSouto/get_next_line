/* HEADER */

#ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#	ifndef BUFFER_SIZE
#		define BUFFER_SIZE 21
#	endif

#	include <stdlib.h>
#	include <unistd.h>

int		findBreak(char *str);
int		updateBuf(char *buf);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
