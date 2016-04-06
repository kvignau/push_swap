# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/03/23 20:03:43 by kvignau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRC = action_algo.c main.c new_algo.c error.c test_list.c reso.c
SRC += push_swap.c ft_ldbl.c display.c ft_atoi_imax.c ft_check.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ft_printf/ all
	gcc -o $(NAME) $(OBJ) -L ft_printf/ -lftprintf

clean:
	make -C ft_printf/ clean
	rm -f $(OBJ)

fclean: clean
	make -C ft_printf/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
