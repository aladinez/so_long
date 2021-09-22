/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:04:28 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/22 16:37:06 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_wall(t_data *data, int x, int y)
{
	int	x1;
	int	y1;
	int	i;

	i = 0;
	x1 = x + TILE_SIZE;
	y1 = y + TILE_SIZE;
	while (y < y1)
	{
		x = x1 - 64;
		while (x < x1)
		{
			my_pixel_put(data, x, y, data->text_data[1][i]);
			x++;
			i++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int	i;

	y = data->y_player;
	i = 0;
	while (y < data->y_player + TILE_SIZE)
	{
		x = data->x_player;
		while (x < data->x_player + TILE_SIZE)
		{
			if (data->text_data[0][i] != data->text_data[0][0])
				my_pixel_put(data, x, y, data->text_data[0][i]);
			x++;
			i++;
		}
		y++;
	}
}

void	draw_ground(t_data *data, int x, int y)
{
	int	x1;
	int	y1;
	int	i;

	i = 0;
	x1 = x + TILE_SIZE;
	y1 = y + TILE_SIZE;
	while (y < y1)
	{
		x = x1 - 64;
		while (x < x1)
		{
			my_pixel_put(data, x, y, data->text_data[2][i]);
			x++;
			i++;
		}
		y++;
	}
}

void	draw_over(t_data *data)
{
	int	i;
	int	j;
	int	x;

	x = 0;
	j = data->res_y / 2 - 32;
	while (j < data->res_y / 2 + 32)
	{
		i = data->res_x / 2 - 32;
		while (i < data->res_x / 2 + 32)
		{
			my_pixel_put(data, i, j, data->text_data[5][x]);
			x++;
			i++;
		}
		j++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->y_squares)
	{
		i = 0;
		while (i < data->x_squares)
		{
			draw_ground(data, i * TILE_SIZE, j * TILE_SIZE);
			if (data->map[j][i] == '1')
				draw_wall(data, i * TILE_SIZE, j * TILE_SIZE);
			else if (data->map[j][i] == 'C')
				draw_sprite(data, i * TILE_SIZE, j * TILE_SIZE);
			else if (data->map[j][i] == 'E')
				draw_exit(data, i * TILE_SIZE, j * TILE_SIZE);
			draw_player(data);
			if (data->gameover)
				draw_over(data);
			i++;
		}
		j++;
	}
}
