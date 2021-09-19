/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:22:30 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/19 17:41:59 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int		ft_keypressed(int key, t_data *data)
{
	int new_x;
	int new_y;
	int x_sqr;
	int y_sqr;

	x_sqr = data->x_player / TILE_SIZE;
	y_sqr = data->y_player / TILE_SIZE;
	if (!data->gameover)
	{
		if (key == 13 )
			y_sqr -= 1;
		else if (key == 1)
			y_sqr += 1;
		else if (key == 2)
			x_sqr += 1;
		else if (key == 0)
			x_sqr -= 1;	
	}
	// printf("collectibles = %d\n", data->collect);
	
	if (data->map[y_sqr][x_sqr] == '0')
	{
		data->x_player = x_sqr * TILE_SIZE;
		data->y_player = y_sqr * TILE_SIZE;
	}
	else if (data->map[y_sqr][x_sqr] == 'C')
	{
		data->map[y_sqr][x_sqr] = '0';
		data->collect--;
		data->x_player = x_sqr * TILE_SIZE;
		data->y_player = y_sqr * TILE_SIZE;
	}
	else if (data->map[y_sqr][x_sqr] == 'E' && data->collect == 0)
	{
		data->gameover = 1;
		data->x_player = x_sqr * TILE_SIZE;
		data->y_player = y_sqr * TILE_SIZE;
	}
	
	return (0);
}

int		ft_keyreleased(int key, t_data *data)
{
	return (0);
}
