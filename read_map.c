/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:36:38 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/17 16:59:04 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void	read_map(t_data *data, char *file)
{
	char	*line;
	int		i;
	int		a;
	int		fd;

	fd = open(file, O_RDONLY);
	data->x_squares = 0;
	data->y_squares = 0;
	while ((i = get_next_line(fd, &line)) >= 0)
	{
		if (*line == '1')
		{
			data->y_squares++;
			a = ft_strlen(line);
            if (data->x_squares != 0 && a != data->x_squares)
            {
                printf("map Errorhh\n");
                exit(1);
            }
			data->x_squares = a;
            
		}
        else 
        {
            printf("map Error\n");
            exit(1);
        }
		free(line);
		if (i == 0)
			break ;
	}
}
