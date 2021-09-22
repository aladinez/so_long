/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:36:38 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/22 16:37:06 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	map_error(void)
{
	printf("map Error\n");
	exit(1);
}

void	read_map(t_data *data, char *file)
{
	char	*line;
	int		i;
	int		a;
	int		fd;

	fd = open(file, O_RDONLY);
	data->x_squares = 0;
	data->y_squares = 0;
	while (get_next_line(fd, &line, &i) >= 0)
	{
		if (*line == '1')
		{
			data->y_squares++;
			a = ft_strlen(line);
			if (data->x_squares != 0 && a != data->x_squares)
				map_error();
			data->x_squares = a;
		}
		else
			map_error();
		free(line);
		if (i == 0)
			break ;
	}
}
