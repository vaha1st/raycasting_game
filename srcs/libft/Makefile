# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masharla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 01:41:08 by masharla          #+#    #+#              #
#    Updated: 2021/03/08 01:23:37 by ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c\
ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c\
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c\
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_diglen.c ft_isinset.c ft_putchar_mod.c ft_putstr_mod.c ft_putnbr_mod.c\
ft_ispunct.c ft_isalnumsign.c ft_isspace.c

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
ft_lst_push_front.c ft_lst_push_back.c

OBJ		= ${SRC:.c=.o}
B_OBJ	= ${BONUS:.c=.o}
СС		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
		${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
	ar rcs $(NAME) $(OBJ)
	
bonus: ${OBJ} ${B_OBJ}
	ar rcs ${NAME} ${OBJ} ${B_OBJ}
	
all: ${NAME}

clean:
	${RM} ${OBJ} ${B_OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus
