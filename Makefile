# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 05:41:35 by bsautron          #+#    #+#              #
#    Updated: 2015/02/18 14:56:01 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_select
SRC = main.c \
	  ft_get_info_for_win.c \
	  ft_outc.c \
	  ft_tcg.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wextra -Wall -Werror
LIB = -L./libft -lft
LIBLDC = -L./libldc -lldc

all: libs $(NAME)

$(NAME): $(OBJ)
	@echo "\033[31m"
	@$(CC) -o $@ $^ $(LIB) $(LIBLDC) -lncurses
	@echo "\033[37m"

libs:
	make -C libft/
	make -C libl/
	make -C libldc/

%.o: %.c
	@echo "\033[33m   $^"
	@$(CC) -I includes/ -c $^ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
