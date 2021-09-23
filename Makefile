# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aez-zaou <aez-zaou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 16:26:38 by aez-zaou          #+#    #+#              #
#    Updated: 2021/09/23 16:26:38 by aez-zaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

GCC			= gcc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

SRCS		= main.c			\
				check_map.c		\
				draw_map.c		\
				draw_map2.c		\
				fill_map.c		\
				find_player.c	\
				gnl.c			\
				key_event.c		\
				read_map.c		\

all : $(NAME)

$(NAME) : $(SRCS)
		$(GCC) $(SRCS) -o $(NAME)

clean :
		rm -f $(NAME)

fclean : clean

re: fclean all