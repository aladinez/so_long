/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 15:13:37 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/22 15:15:08 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

void	draw_sprite(t_data *data, int x, int y)
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
			if (data->text_data[3][i] != data->text_data[3][0])
				my_pixel_put(data, x, y, data->text_data[3][i]);
			x++;
			i++;
		}
		y++;
	}
}

void	draw_exit(t_data *data, int x, int y)
{
	int	x1;
	int	y1;
	int	i;

	x1 = x + TILE_SIZE;
	y1 = y + TILE_SIZE;
	i = 0;
	while (y < y1)
	{
		x = x1 - 64;
		while (x < x1)
		{
			if (data->text_data[4][i] != data->text_data[4][0])
				my_pixel_put(data, x, y, data->text_data[4][i]);
			x++;
			i++;
		}
		y++;
	}
}
