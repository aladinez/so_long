/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:59:45 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/19 17:21:42 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void    find_player(t_data *data)
{
    int i;
	int j;

	j = 0;
	while (j < data->y_squares)
	{
		i = 0;
		while (i < data->x_squares)
		{
			if (data->map[j][i] == 'P')
            {
                data->map[j][i] = '0';
                data->x_player = i * TILE_SIZE;
                data->y_player = j * TILE_SIZE;
            }	
			i++;
		}
		j++;
	}
}