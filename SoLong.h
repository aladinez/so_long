/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SoLong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcadmin <mcadmin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:37:24 by aez-zaou          #+#    #+#             */
/*   Updated: 2021/09/20 15:52:27 by mcadmin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H

# define HEADER_H
# define TILE_SIZE 64


# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
#include <fcntl.h>

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
    int         res_x;
    int         res_y;
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
}				t_data;

int				g_bpp;

int		ft_strlen(char *str);
void	fill_map(t_data *data, char *argv);
void	fill_map1(t_data *data, int i, char *line);
void	read_map(t_data *data, char *file);
void	allocate_for_map(t_data *data);
static char	*ft_strjoin(char *s, char c);
int			get_next_line(int fd, char **line);
void    find_player(t_data *data);
void	my_pixel_put(t_data *data, int x, int y, int color);
void draw_map(t_data *data);
int		ft_keypressed(int key, t_data *data);
int		ft_keyreleased(int key, t_data *data);
int		exit_game(t_data *data);
void	map_error();




#endif