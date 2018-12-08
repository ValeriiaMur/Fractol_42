# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 16:18:04 by vmuradia          #+#    #+#              #
#    Updated: 2018/12/07 17:10:33 by vmuradia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
SRC = 	*.c
HEADERS = fractol.h
LIBFT = libft/libft.a
MINILIBX = minilibx/liblmx.a
OBJ=$(SRC:.c=.o)
GREEN = \033[1;32m

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJ)
		Make -C libft
		Make -C minilibx
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I $(HEADERS) -L. $(LIBFT) -L ./minilibx -lmlx -framework OpenGL -framework AppKit

		@echo "$(GREEN)Project successfully compiled"

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC)
$(LIBFT):
		make libft
$(MINILIBX):
		make minilibx

.PHONY : clean fclean re

clean :
		-rm -f $(OBJ)
		@echo "$(GREEN)All object files are deleted"

fclean : clean
		make fclean -C libft
		-rm -f $(NAME)
		@echo "$(GREEN)Cleaned everything"

re : fclean all
