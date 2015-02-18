# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 05:41:35 by bsautron          #+#    #+#              #
#    Updated: 2015/02/18 10:27:05 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_select
SRC = main.c \
	  ft_get_win_size.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wextra -Wall -Werror
LIB = -L./libft -lft

all: lft $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31m"
	@$(CC) -o $@ $^ $(LIB) -lncurses
	@echo "\033[37m"

lft:
	make -C libft/

%.o: %.c
	@echo "\033[33m   $^"
	@$(CC) -I libft/includes/ -c $^ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
