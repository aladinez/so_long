/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcadmin <mcadmin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:35:13 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/20 16:13:08 by mcadmin          ###   ########.fr       */
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


void	get_texture_data(t_data *data)
{
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/avatar.xpm"
					, &data->img_width, &data->img_height);
	data->text_data[0] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/bricks.xpm"
					, &data->img_width, &data->img_height);
	data->text_data[1] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/grass.xpm"
					, &data->img_width, &data->img_height);
	data->text_data[2] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/sprite.xpm"
					, &data->img_width, &data->img_height);
	data->text_data[3] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/exit.xpm"
					, &data->img_width, &data->img_height);
	data->text_data[4] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
	data->text_img = mlx_xpm_file_to_image(data->mlx_ptr, "textures/end.xpm"
					, &data->img_width, &data->img_height);
	data->text_data[5] = (int *)mlx_get_data_addr(data->text_img
					, &g_bpp, &g_bpp, &g_bpp);
}

void	check_map_errors(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (data->map[0][++i])
		if (data->map[0][i] != '1' || data->map[data->y_squares - 1][i] != '1')
			map_error();
	j = -1;
	while (++j < data->y_squares)
		if (data->map[j][0] != '1' || data->map[j][data->x_squares - 1] != '1')
			map_error();
			// to check if this is working well.
}

int main(int argc, char *argv[])
{
    t_data data;

	data.gameover = 0;
	data.steps = 0;
	read_map(&data, argv[1]);
	allocate_for_map(&data);
	fill_map(&data, argv[1]);
	check_map_errors(&data);
	find_player(&data);
    data.res_x = data.x_squares * TILE_SIZE;
    data.res_y = data.y_squares * TILE_SIZE;
    data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr
								, data.res_x, data.res_y, "Cub3D");
	data.img_ptr = mlx_new_image(data.mlx_ptr, data.res_x, data.res_y);
	data.img_data = (int *)mlx_get_data_addr(data.img_ptr
								, &g_bpp, &g_bpp, &g_bpp);
	get_texture_data(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_hook(data.win_ptr, 2, 0, ft_keypressed, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_game, &data);     
	mlx_loop_hook(data.mlx_ptr, ft_render, &data);
    mlx_loop(data.mlx_ptr);
    return 0;
}

