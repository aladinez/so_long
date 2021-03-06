/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:19:02 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/23 16:37:58 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	allocate_for_map(t_data *data)
{
	int	i;

	if (data->y_squares > 22 || data->x_squares > 40)
	{
		printf("Map resollution is too big\n");
		exit(1);
	}
	i = 0;
	data->map = (char **)malloc(data->y_squares * sizeof(char *));
	while (i < data->y_squares)
	{
		data->map[i] = (char *)malloc(data->x_squares * sizeof(char));
		i++;
	}
}

void	fill_map(t_data *data, char *argv)
{
	char	*line;
	int		i;
	int		ret;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line, &ret) >= 0)
	{
		if (*line == 0)
		{
			free(line);
			if (!ret)
				break ;
			continue ;
		}
		if (*line == '1' || *line == ' ' || *line == '2'
			|| *line == '0' || *line == '6')
		{
			fill_map1(data, i, line);
			i++;
		}
		free(line);
	}
}

void	fill_map1(t_data *data, int i, char *line)
{
	int		j;

	j = 0;
	while (j < data->x_squares)
	{
		data->map[i][j] = line[j];
		j++;
	}
	data->map[i][j] = 0;
}
