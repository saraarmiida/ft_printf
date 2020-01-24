# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spentti <spentti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 14:03:19 by spentti           #+#    #+#              #
#    Updated: 2020/01/24 20:28:52 by spentti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf                                                                              
FLAGS = -Wall -Wextra -Werror
SRC = srcs/*.c main.c

all: $(NAME)

$(NAME):
	gcc libft/libft.a $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all