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

NAME = push_swap

SRC = main.c \
create_list/create_list.c \
movements/mov_push.c \
movements/mov_reverse_rotate.c \
movements/mov_rotate.c \
movements/mov_swap.c \
create_list/list_utils.c \
create_list/temp_functions.c \
basic_utils.c \
basic_utils_2.c \
ft_split.c \
sort_small/sort_small.c \
sort_big/sort_big.c \
sort_big/sort_big_utils.c \
sort_big/execute_best_moves.c \
sort_big/find_cheapest_move.c \

OBJ = $(SRC:.c=.o)

#CC = cc
#FLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
RM = rm -f
AR = ar rcs

%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus