# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 12:21:35 by bsautron          #+#    #+#              #
#    Updated: 2015/02/18 13:22:53 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = ft_lstdc_rinit.c \
	  ft_lstdc_create.c \
	  ft_lstdc_add.c \
	  ft_lstdc_add_back.c \
	  ft_lstdc_delfirst.c \
	  ft_lstdc_print.c
OBJ = $(SRC:.c=.o)
NAME = libldc.a
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[37m"

%.o: %.c
	@echo "\033[31m   $^"
	@$(CC) $(CFLAGS) -I ../includes/ -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
