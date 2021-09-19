/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:35:13 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/19 17:42:08 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SoLong.h"

int		exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	int		*var;
	int		index;
	int		new_y;

	var = (int*)mlx_get_data_addr(data->img_ptr, &g_bpp, &g_bpp, &g_bpp);
	if (x < data->res_x && x >= 0 && y < data->res_y && y >= 0)
	{
		var[x + data->res_x * y] = color;
	}
}

int		ft_render(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->res_x, data->res_y);
	data->img_data = (int *)mlx_get_data_addr(data->img_ptr
											, &g_bpp, &g_bpp, &g_bpp);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

// void	initialise(t_data *data)
// {
// 	data->collect = 0;
// }

int main(int argc, char *argv[])
{
    t_data data;

	data.gameover = 0;
	read_map(&data, argv[1]);
	// printf("%d -- %d\n", data.y_squares, data.x_squares);
	allocate_for_map(&data);
	fill_map(&data, argv[1]);
	find_player(&data);
    
	int i =0;
	while (data.map[i])
	{
		printf("%s\n", data.map[i]);
		i++;
	}
    data.res_x = data.x_squares * TILE_SIZE;
    data.res_y = data.y_squares * TILE_SIZE;
    data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr
								, data.res_x, data.res_y, "Cub3D");
	data.img_ptr = mlx_new_image(data.mlx_ptr, data.res_x, data.res_y);
	data.img_data = (int *)mlx_get_data_addr(data.img_ptr
								, &g_bpp, &g_bpp, &g_bpp);
	



	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 2, 0, ft_keypressed, &data);
	// mlx_hook(data.win_ptr, 3, 0, ft_keyreleased, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_game, &data);     
	mlx_loop_hook(data.mlx_ptr, ft_render, &data);
    mlx_loop(data.mlx_ptr);
    return 0;
}

