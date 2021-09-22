/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:29:27 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/22 16:39:41 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_bad_chars(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->y_squares)
	{
		i = 0;
		while (i < data->x_squares)
		{
			if (data->map[j][i] == 'C')
				data->collect++;
			if (data->map[j][i] != 'P' && data->map[j][i] != 'C'
				&& data->map[j][i] != 'E' && data->map[j][i] != '0'
				&& data->map[j][i] != '1')
				map_error();
			i++;
		}
		j++;
	}
	if (!data->collect)
		map_error();
}

void	check_map_errors(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[0][++i])
		if (data->map[0][i] != '1' || data->map[data->y_squares - 1][i] != '1')
			map_error();
	j = -1;
	while (++j < data->y_squares)
		if (data->map[j][0] != '1' || data->map[j][data->x_squares - 1] != '1')
			map_error();
	data->collect = 0;
	check_bad_chars(data);
}
