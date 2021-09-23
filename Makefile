NAME		= so_long

GCC			= gcc -Wall -Wextra -Werror

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