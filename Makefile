# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isousa-s <isousa-s@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 18:19:11 by isousa-s          #+#    #+#              #
#    Updated: 2025/02/14 18:19:11 by isousa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = push_swap.c \
push_swap.c \

OBJ = ${SRC:.c=.o}

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

%.o: %.c push_swap.h
	${CC} ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): ${OBJ}
	${AR} ${NAME} ${OBJ}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus