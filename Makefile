# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spentti <spentti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 14:03:19 by spentti           #+#    #+#              #
#    Updated: 2020/01/27 11:42:29 by spentti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBNAME = libft.a
LIBFT = libft
FLAGS = -Wall -Wextra -Werror
INC = includes/ft_printf.h
SRC = srcs/c_char.c \
		srcs/c_double.c \
		srcs/c_hex.c \
		srcs/c_int.c \
		srcs/c_octal.c \
		srcs/c_pointer.c \
		srcs/c_unsigned.c \
		srcs/conversions.c \
		srcs/ft_printf.c \
		srcs/modifiers.c \
		srcs/parse_format.c \
		srcs/utils.c \

OBJ = c_char.o \
		c_double.o \
		c_hex.o \
		c_int.o \
		c_octal.o \
		c_pointer.o \
		c_unsigned.o \
		conversions.o \
		ft_printf.o \
		modifiers.o \
		parse_format.o \
		utils.o \

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ):
	@gcc $(FLAGS) -c $(SRC) -I $(INC)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all