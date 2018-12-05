# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 09:32:23 by vmuradia          #+#    #+#              #
#    Updated: 2018/10/27 14:12:46 by vmuradia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -c
AR = ar rc
CFLAGS = -Wall -Wextra -Werror
HEADER = libft.h
SRC = *.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
				$(CC) $(CFLAGS) $(SRC) -I $(HEADER)
				$(AR) $(NAME) $(OBJ)
				ranlib $(NAME)

clean:
				-rm -f $(OBJ)

fclean: clean
				-rm -f $(NAME)

re: fclean all
