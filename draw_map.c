/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:04:28 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/19 17:40:27 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void draw_wall(t_data *data, int x, int y)
{
	int x1;
	int y1;

	x1 = x + TILE_SIZE;
	y1 = y + TILE_SIZE;
	while (y < y1)
	{
		x = x1 - 64;
		while (x < x1){
			my_pixel_put(data, x, y, 0xDF776B);
			x++;
		}
		y++;
	}
}

void draw_player(t_data *data)
{
	int x;
	int y;

	y = data->y_player;
	while (y < data->y_player + TILE_SIZE)
	{
		x = data->x_player;
		while (x < data->x_player + TILE_SIZE){
			my_pixel_put(data, x, y, 0xF043C3);
			x++;
		}
		y++;
	}
}

void draw_sprite(t_data *data, int x, int y)
{
	int x1;
	int y1;

	x1 = x + TILE_SIZE;
	y1 = y + TILE_SIZE;
	while (y < y1)
	{
		x = x1 - 64;
		while (x < x1){
			my_pixel_put(data, x, y, 0xDFF85F);
			x++;
		}
		y++;
	}
}

void draw_exit(t_data *data, int x, int y)
{
	int x1;
	int y1;

	x1 = x + TILE_SIZE;
	y1 = y + TILE_SIZE;
	while (y < y1)
	{
		x = x1 - 64;
		while (x < x1){
			my_pixel_put(data, x, y, 0xEA1B41);
			x++;
		}
		y++;
	}
}

void draw_ground(t_data *data, int x, int y)
{
	int x1;
	int y1;

	x1 = x + TILE_SIZE;
	y1 = y + TILE_SIZE;
	while (y < y1)
	{
		x = x1 - 64;
		while (x < x1){
			my_pixel_put(data, x, y, 0x5AB5D9);
			x++;
		}
		y++;
	}
}

void    draw_over(t_data *data)
{
    int i;
    int j;

    j = 0;
    while (j < data->res_y)
    {
        i = 0;
        while (i < data->res_x)
        {
            my_pixel_put(data, i, j, 0x0);
            i++;
        }
        j++;
    }
}


void draw_map(t_data *data)
{
	int i;
	int j;
	
	j = 0;
    data->collect = 0;
	while (j < data->y_squares)
	{
		i = 0;
		while (i < data->x_squares)
		{
			draw_ground(data, i * TILE_SIZE, j * TILE_SIZE);
			if (data->map[j][i] == '1')
				draw_wall(data, i * TILE_SIZE, j * TILE_SIZE);
			else if (data->map[j][i] == 'C')
            {
                data->collect++;
				draw_sprite(data, i * TILE_SIZE, j * TILE_SIZE);
            }
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