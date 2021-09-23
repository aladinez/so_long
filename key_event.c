/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:22:30 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/23 16:38:39 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

void	event_handling(t_data *data, int x_sqr, int y_sqr)
{
	if ((data->map[y_sqr][x_sqr] == '0' || data->map[y_sqr][x_sqr] == 'C'
		|| (data->map[y_sqr][x_sqr] == 'E' && data->collect == 0))
		&& (x_sqr != (data->x_player / TILE_SIZE)
		|| y_sqr != (data->y_player / TILE_SIZE)))
	{
		printf("step count : %d\n", ++data->steps);
		data->x_player = x_sqr * TILE_SIZE;
		data->y_player = y_sqr * TILE_SIZE;
	}
	if (data->map[y_sqr][x_sqr] == 'C')
	{
		data->map[y_sqr][x_sqr] = '0';
		data->collect--;
	}
	else if (data->map[y_sqr][x_sqr] == 'E' && data->collect == 0)
		data->gameover = 1;
}

int	ft_keypressed(int key, t_data *data)
{
	int	x_sqr;
	int	y_sqr;

	x_sqr = data->x_player / TILE_SIZE;
	y_sqr = data->y_player / TILE_SIZE;
	if (key == 53)
		exit_game(data);
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
	event_handling(data, x_sqr, y_sqr);
	return (0);
}
