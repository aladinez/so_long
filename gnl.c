/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:30:25 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/22 15:42:54 by aez-zaou         ###   ########.fr       */
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
	str = (char *)malloc(i + 2);
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

int	get_next_line(int fd, char **line, int *ret)
{
	char	*buffer;
	int		flag;

	buffer = (char *)malloc(2);
	if (!line || !buffer)
	{
		*ret = -1;
		return (-1);
	}
	*line = (char *)malloc(1);
	*line[0] = '\0';
	flag = read(fd, buffer, 1);
	while (flag > 0)
	{
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buffer[0]);
		flag = read(fd, buffer, 1);
	}
	free(buffer);
	*ret = flag;
	return (flag);
}
