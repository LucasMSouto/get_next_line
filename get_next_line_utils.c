/* HEADER */

#include "get_next_line.h"

int		findBreak(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int		updateBuf(char *buf)
{
	int	i;
	int	j;
	int	isNewLine;

	i = 0;
	j = 0;
	isNewLine = 0;
	while (buf[i])
	{
		if (isNewLine)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			isNewLine = 1;
		buf[i++] = 0;
	}
	return (isNewLine);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		strIndex;

	i = 0;
	strIndex = 0;
	str = malloc(findBreak(s1) + findBreak(s2) + 1);
	if (!str)
		return (0);
	while (s1 && s1[i])
		str[strIndex++] = s1[i++];
	free (s1);
	i = 0;
	while (*s2)
	{
		str[strIndex++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	str[strIndex] = '\0';
	return (str);
}
