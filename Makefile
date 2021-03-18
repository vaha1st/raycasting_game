# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masharla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 01:41:08 by masharla          #+#    #+#              #
#    Updated: 2021/03/18 18:10:26 by ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D

SRC		= srcs/cub3d.c srcs/gnl/get_next_line.c srcs/utils/parser_utils.c \
		srcs/parser.c srcs/layers/minimap.c srcs/utils/screen_utils.c \
		srcs/utils/player_utils.c srcs/utils/parser_map_checker.c \
		srcs/utils/ray_utils.c srcs/layers/floor_ceiling.c \
		srcs/layers/first_view.c srcs/events.c\
		srcs/utils/init_structures.c srcs/utils/texture_utils.c srcs/save.c\
		srcs/utils/shutdown.c srcs/sprite.c srcs/utils/events_utils.c

BONUS	= 

FH		= includes/*.h
LIBFT	= ./srcs/libft/libft.a
MLX		= ./srcs/minilibx/libmlx.a
FRWKS	= -framework OpenGL -framework Appkit

OBJ		= ${SRC:.c=.o}
СС		= gcc
FLAGS	= -Wall -Wextra -Werror
INCL	= -I .
RM		= rm -f


$(NAME): ${OBJ} ${FH}
	$(MAKE) bonus -C ./srcs/libft
	$(MAKE) -C ./srcs/minilibx
	${CC} ${FLAGS} ${INCL} -o ${NAME} ${LIBFT} ${MLX} ${OBJ} ${FRWKS}
	
bonus: all
	
all: ${NAME}

clean:
	$(MAKE) clean -C ./srcs/libft
	$(MAKE) clean -C ./srcs/minilibx
	${RM} ${OBJ}

fclean: clean
	$(MAKE) fclean -C ./srcs/libft
	$(MAKE) clean -C ./srcs/minilibx
	${RM} ${NAME}
	${RM} screenshot.bmp

re: fclean all

.PHONY:	all clean fclean re bonus
