# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masharla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 01:41:08 by masharla          #+#    #+#              #
#    Updated: 2021/03/03 14:27:52 by ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

SRC		= cub3d.c srcs/gnl/get_next_line.c srcs/utils/parser_utils.c \
		srcs/parser.c srcs/minimap.c srcs/utils/screen_utils.c \
		srcs/utils/player_utils.c srcs/utils/parser_map_checker.c

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

re: fclean all

.PHONY:	all clean fclean re bonus
