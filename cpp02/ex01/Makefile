# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 21:39:52 by kkhai-ki          #+#    #+#              #
#    Updated: 2024/11/23 22:18:31 by kkhai-ki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
ORANGE = \033[0;38;5;166m

NAME = fixed

CC = clang++
CFLAGS = -Wall -Wextra -Werror -I. -std=c++98 -pedantic -g3

SRC =	main.cpp	\
		Fixed.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
