# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masharla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 01:41:08 by masharla          #+#    #+#              #
#    Updated: 2021/02/19 19:11:34 by ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

SRC		= main.c srcs/gnl/get_next_line.c \
	srcs/utils/parser_utils.c srcs/parser.c

BONUS	= 

FH		= includes/cub3d.h

OBJ		= ${SRC:.c=.o}
СС		= gcc
FLAGS	= -Wall -Wextra -Werror
INCL	= -I .
RM		= rm -f


$(NAME): ${OBJ} ${FH}
	$(MAKE) bonus -C ./srcs/libft
	${CC} ${FLAGS} ${INCL} -o ${NAME} ./srcs/libft/libft.a ${OBJ}
	
bonus: all
	
all: ${NAME}

clean:
	$(MAKE) clean -C ./srcs/libft
	${RM} ${OBJ}

fclean: clean
	$(MAKE) fclean -C ./srcs/libft
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus
