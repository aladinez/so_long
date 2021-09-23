/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:37:24 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/23 16:38:39 by aez-zaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# define TILE_SIZE 64

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			res_x;
	int			res_y;
	int			x_squares;
	int			y_squares;
	char		**map;
	int			x_player;
	int			y_player;
	int			collect;
	int			gameover;
	int			steps;
	void		*text_img;
	int			*text_data[6];
	int			img_height;
	int			img_width;
	int			bpp;
}				t_data;

int			ft_strlen(char *str);
void		fill_map(t_data *data, char *argv);
void		fill_map1(t_data *data, int i, char *line);
void		read_map(t_data *data, char *file);
void		allocate_for_map(t_data *data);
int			get_next_line(int fd, char **line, int *ret);
void		find_player(t_data *data);
void		my_pixel_put(t_data *data, int x, int y, int color);
int			ft_render(t_data *data);
void		get_texture_data(t_data *data);
void		check_bad_chars(t_data *data);
void		check_map_errors(t_data *data);
void		draw_wall(t_data *data, int x, int y);
void		draw_player(t_data *data);
void		draw_ground(t_data *data, int x, int y);
void		draw_over(t_data *data);
void		draw_map(t_data *data);
void		draw_sprite(t_data *data, int x, int y);
void		draw_exit(t_data *data, int x, int y);
int			ft_keypressed(int key, t_data *data);
void		event_handling(t_data *data, int x_sqr, int y_sqr);
int			exit_game(t_data *data);
void		map_error(void);

#endif
