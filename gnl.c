/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:30:25 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/17 15:39:11 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

static char	*ft_strjoin(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char *)malloc(i + 2)))
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	if (!line || !(*line = (char *)malloc(1)) || !buffer)
		return (-1);
	*line[0] = '\0';
	while ((flag = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buffer[0]);
	}
	free(buffer);
	return (flag);
}