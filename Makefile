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
create_list.c \
temp_functions.c \
movements/mov_push.c \
movements/mov_reverse_rotate.c \
movements/mov_rotate.c \
movements/mov_swap.c \
list_utils.c \
basic_utils.c \
check_moves_in_a.c \
push_and_sort.c \
sort_small.c \
sort_big.c \
chunks.c \
check_moves.c \
cal_in_b.c \

OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Werror -Wextra
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