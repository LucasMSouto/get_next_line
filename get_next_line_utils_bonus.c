/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-matt <lde-matt@student.42.pt>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:37:58 by lde-matt          #+#    #+#             */
/*   Updated: 2023/02/22 14:10:31 by lde-matt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_break(char *str)
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

int	update_buf(char *buf)
{
	int	i;
	int	j;
	int	is_nl;

	i = 0;
	j = 0;
	is_nl = 0;
	while (buf[i])
	{
		if (is_nl)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			is_nl = 1;
		buf[i++] = '\0';
	}
	return (is_nl);
}

char	*strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		str_index;

	i = 0;
	str_index = 0;
	str = malloc(find_break(s1) + find_break(s2) + 1);
	if (!str)
		return (0);
	while (s1 && s1[i])
		str[str_index++] = s1[i++];
	free (s1);
	i = 0;
	while (*s2)
	{
		str[str_index++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	str[str_index] = '\0';
	return (str);
}
